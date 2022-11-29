#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

#include"char_code.h"

#define NUMBER 128
using namespace std;



int main(){
    cout << "-----------------" << endl;
    cout << "HuffmanCode v1.0 |" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "操作命令说明：                                                    |" << endl;
    cout << "* 统计输入文件字符频度频度并对字符集编码，输出至文件（基本要求）:1|" << endl;
    cout << "* 对整个文件编码并保存编码结果到一个二进制文件（中级要求）:2      |" << endl;
    cout << "* 文件解码并将解码结果保存为一个文本文件（高级要求）:3            |" << endl;
    cout << "* 退出:0                                                          |" << endl;
    cout << "------------------------------------------------------------------" << endl;
    int n = 0;
    char s[NUMBER];
    int w[NUMBER];

    char option;
    cin >> option;
    while (option != '0') {
        switch(option) {
            case '1':
                cout << "Running option 1..." << endl;
                Stat(s,w,n);
                // char_code;
                cout << "Complete." << endl;
                break;
            case '2':
                cout << "Running option 2..." << endl;
                //File_Code();
                cout << "Complete." << endl;
                break;
            case '3':
                cout << "Runing option 3..." << endl;
                //File_Decode();
                cout << "Complete." << endl;
                break;
            case '0':
                break;
            
        }
        cin >> option;
    }

}