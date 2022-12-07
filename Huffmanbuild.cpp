#pragma once
#include <iostream>
#include <fstream>
#include "minHeap.cpp"
#include "Huffmancode.cpp"
//个人报告问题
//1.修改小堆类函数实现
//2.函数派生类向基类转换问题（不是个人任务）
//3. undefined reference to `HuffTree<char>* HuffmanBuild<char>(char*, int*, int)'
//4.模板类必须包含cpp文件
//5.函数声明用了模板，实现时忘记

extern char filename[50];
extern HuffTree<char>* statictree;

using namespace std;
void  Stat(char *s,int *w,int &num);
//template <class Elem>
HuffTree<char>* HuffmanBuild(char *s,int *w,int num);

void char_code() {

    int n = 0;
    char s[NUMBER];
    int w[NUMBER];
    Stat(s,w,n);
    for(int i = 0;i<n;i++){
        cout<<s[i];
        cout<<" ";
        cout<<w[i]<<endl;
    }
//    undefined reference to `HuffTree<char>* HuffmanBuild<char>(char*, int*, int)'
    HuffTree<char> *tree;
    tree = HuffmanBuild(s, w, n);
    statictree = tree;

    char* m = new char[1];
    HuffmanCode(tree->root(), m, 1);
    // tree->print();

//    return 0;
//    int *a;
//    a = new int[NUMBER]{5,10,12,8,15,6,17,2,4,7,18,3};
//    minHeap<int>* he = new minHeap<int>(a,12,NUMBER);
//    he->buildHeap();
//    he->print();
//    he->insert(1);
//    he->print();
//    he->removeFirst();
//    he->print();




//    for (int i = 0; i < 4; ++i) {
//        cout<<a[i]<<" ";
//    }

}

void  Stat(char *s,int *w,int &num){
    cout<<"please enter the file's name:\n";
    
    char c;

    /**
     * @brief cin.getline()此处报未知错误
     * 
     */
    //cin.getline(filename,50);

    cin >> filename;
    ifstream ifs;
    ifs.open(filename,ios::in);
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    for(int i = 0;i<NUMBER;i++){
        w[i] = 0;
    }
    while(!ifs.eof()){
        if(ifs.good()){
            ifs>>noskipws>>c;
            //cout<<c;
            if(!ifs.eof()) {
                w[c]++;
                s[c] = c;
            }
        }
    }
    /*for(int i = 0;i<NUMBER;i++){
        cout<<w[i];
        cout<<" ";
    }
    cout<<endl;*/
    int j = 0;
    int k[NUMBER];
    char q[NUMBER];
    for(int i = 0;i<NUMBER;i++){
        k[i] = 0;
    }
    for(int i = 0;i<NUMBER;i++){
        if(!w[i]==0){
            k[j] = w[i];
            q[j] = s[i];
            j++;
        }
    }
    for(int i = 0;i<NUMBER;i++){
        w[i] = k[i];
    }
    for(int i = 0;i<NUMBER;i++){
        s[i] = q[i];
    }
    /*for(int i = 0;i<NUMBER;i++){
        cout<<w[i];
        cout<<" ";
    }*/
    num = j;
}


HuffTree<char>* HuffmanBuild(char *s,int *w,int num){
    HuffTree<char>* trees[NUMBER];
    HuffTree<char> *temp,*t1,*t2;
    for (int i = 0; i < num; ++i) {
        trees[i] = new HuffTree<char>(s[i],w[i]);
    }
    minHeap<char>* Forest = new minHeap<char>(trees,num,128);
    Forest->buildHeap();
    while(Forest->heapSize()!=1){
        t1 = Forest->removeFirst();
//        t1->print();
        t2 = Forest->removeFirst();
        temp = new HuffTree<char>(t1,t2);
//        temp->print();
//        cout<<"  1"<<endl;
        Forest->insert(temp);
    }
    return temp;
}