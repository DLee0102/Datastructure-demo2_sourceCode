#pragma once
#include"HuffTree.cpp" 
#include<String.h> 
#include<fstream>
#include<unordered_map>

extern unordered_map<char,string> huffmanCodes;
char** codeList = new char* [100];
int count = 0;

/**
 * @brief 判断写入次数以用于文件写入时判断是否刷新文件内容
 * 
 */
static int write_count = 0;
static int stack_count = 1;

void HuffmanCode(HuffNode<char> *ht1,char * code,int length)
{
	//printf("")
	
	//printf("%d",count);
//	count = 8;



	if(ht1==NULL) {stack_count--;return;}
	if(ht1->isLeaf()) 
	{
		write_count++;
		//printf("into leaf\n");
		LeafNode<char>* ht1temp = (LeafNode<char>*)ht1;
		
		//strcpy(codeList[count],code);
		//char *mm = "temp";
		//String mm = "temp";
		//char * ini = code;
		//codeList[count] = ini;
		
		codeList[count] = (code+1);
//		
		//printf("%s",codeList[count]);

	    ofstream ofs;
		/**
		 * @brief 函数为递归调用，为避免反复追加写入同一文件的情况，首次写入需截断
		 * 
		 */
		if (write_count==1) {
			ofs.open("code_result.txt",ios::out);	
    		if(!ofs.is_open()){
        		cout<<"文件打开失败"<<endl;
    		}else{
				ofs << ht1temp->val()->val() << "   " << ht1temp->weight() << "   " << codeList[count] << endl;
    		}
    		//关闭文件
    		ofs.close();
		} else {
	    	ofs.open("code_result.txt",ios::app);	
    		if(!ofs.is_open()){
        		cout<<"文件打开失败"<<endl;
    		}else{
				ofs << ht1temp->val()->val() << "   " << ht1temp->weight() << "   " << codeList[count] << endl;
    		}
    		//关闭文件
    		ofs.close();
		}
		huffmanCodes[ht1temp->val()->val()] = codeList[count];
		printf("%c,%d, %s\n",ht1temp->val()->val(),ht1temp->weight(),codeList[count]);
		//ht1temp->val()->val(),
		++count;
		stack_count--;
		return;
	}
	
	IntlNode<char>* ht1temp = (IntlNode<char>*)ht1;
	
	if(ht1temp->left()!=NULL)
	{
		char * temp_c = new char[length+1];

		/**
		 * @brief 丁利改
		 * 
		 */
		//if(*code!=NULL)
		if(code!=NULL)
			strcpy(temp_c,code);
		int len = length;++len;
		temp_c[length] = '0';
		temp_c[len] = '\0';
		
		//printf("%s\n",(temp_c+1));
//		printf("  %c  ",temp_c[0]);
		
		//printf("entering left\n");
		stack_count++;
		HuffmanCode(ht1temp->left(),temp_c,len);
	}
	if(ht1temp->right()!=NULL)
	{
		char * temp_c = new char[length+1];
		if(code!=NULL)
			strcpy(temp_c,code);
		strcpy(temp_c,code);
		int len = length;++len;
		temp_c[length] = '1';
		temp_c[len] = '\0';
		
		//printf("%s\n",(temp_c+1));
//		printf("  %c  ",temp_c[0]);
		
		printf("entering right\n");
		stack_count++;
		HuffmanCode(ht1temp->right(),temp_c,len);
	}

	/**
	 * @brief 在最后一次弹出栈的时候需要将所有全局变量重置，
	 * 防止同一个进程中反复调用函数时全局变量被重复修改
	 * 
	 */
	stack_count--;
	if (stack_count==0) {
		write_count = 0;
		stack_count = 1;
		count = 0;
	}
}
