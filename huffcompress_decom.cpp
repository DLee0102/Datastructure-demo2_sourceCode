#include"huffcompress_decom.h"
#include"Bit.cpp"
#include"HuffTree.cpp"
#include <unordered_map>

using namespace std;

extern unordered_map<char,string> huffmanCodes;
extern char filename[50];
extern HuffTree<char>* statictree;


void file_compress() {
    //打开原文件，并将编码结果写入"file_result.txt"文件
	    ifstream ifs(filename,ios::in);
	    ofstream ofs("file_compress.txt",ios::out);
        char getin;
        int readcharNum = 0;
        Bit bit;
        int writecharNum = 0; 
    	int hold = 0;
        double compressionRatio = 0.0;

	    //如果原文件不存在则提示并退出
	    if(!ifs.is_open()){
	        cout<<filename<<"打开失败"<<endl;
	        return;
	    }
	    //依次读取原文件的每个字符
	    while((getin=ifs.get())!=EOF){
	        //读入的字符数加1
	        readcharNum++;
	        //获取该字符对应的哈夫曼编码
	        string code=huffmanCodes[getin];
	        //依次将编码对应的二进制位写入一个byte里
	        for(auto& it:code){
	            //先左移一位，再对最后一位赋值
	            bit.ch<<=1;
	            //对bit进行按位或操作 
	            bit.ch|=(int)(it-'0');
	            
	            bit.bitsNum++;
	            //如果bit的八个位都已被写入，则进入if语句
	            if(bit.bitsNum==bitsize){
	                //将改byte的数据写入文件
	                ofs<<bit.ch;
	                //重置已写位
	                bit.bitsNum=0;
	                //写出字符数加1
	                writecharNum++;
	            }
	        }
	    }
	    //如果最后剩下的字符无法凑成一个bit
	    if(bit.bitsNum!=0){
	        //将剩下的位用'0'占位
	        for(;bit.bitsNum<bitsize;bit.bitsNum++){
	            bit.ch<<=1;
	        	hold++;
	        }
	        //将最后的bits写入文件
			ofs<<bit.ch;
	        //写出字符数加1
	        writecharNum++;
	    }
	    //关闭文件
	    ifs.close();
	    ofs.close();
	    //计算压缩比=写出字符数/读入字符树

        /**
         * @brief 若变量未初始化则会出错
         * 
         */
	    compressionRatio=((double)writecharNum/(double)readcharNum)*100;
	    cout<<"压缩比为："<<compressionRatio<<"% 详情请看file_compress.txt"<<endl;
}

void file_reconstruct() {
    bool choice;
    char restch;
    int restchNum = 0;
    char getin;
    int hold = 0;

    //打开压缩文件，并将结果写入"file_decode.txt"
    FILE* fp= fopen("file_compress.txt","rb");
    ofstream ofs("file_reconstruct.txt",ios::out|ios::binary);

    // //记录当前遍历位置为树根
    // int point=root;
    HuffNode<char>* point = statictree->root();

    //初始化上一个字符的未读位为0
    restchNum=0;
    while(true){
        //依次读取一个字符
        getin= getc(fp);
        //如果文件后没有别的字符则退出循环
        if(feof(fp)){
            break;
        }
        //初始化当前位读数为一个byte的大小
        int size=bitsize;
        //只处理占位符以前的位
        while(size>hold){
            //将上一个字符剩下的部分读完
            if(restchNum>0){
                choice=(bool)((restch&128)==128);
                restch<<=1;
                restchNum--;
            }else{
                //上一个字符剩下部分读完以后，再读取当前新读入的这个字符
                choice=(bool)((getin&128)==128);
                getin<<=1;
                size--;
            }
            if(!choice){
                //如果choice为false，则进入左子树
                // point=nodes[point].lchild;
                point = ((IntlNode<char>*)point)->left();
            }else{
                //如果choice为true，则进入右子树
                point = ((IntlNode<char>*)point)->right();
            }
            //如果当前的结点为叶结点，则将对应的字符写入文件，并将位置重置为树根
            if(point->isLeaf()) {
                ofs << ((LeafNode<char>*)point)->val()->val();
                point = statictree->root();
            }
        }
        //将剩下的部分保存，并重置未读的比特数
        restch=getin;
        restchNum=hold;
    }
    //关闭文件
    fclose(fp);
    ofs.close();
    cout<<"解压成功！详情请看file_reconstruct.txt"<<endl;
}