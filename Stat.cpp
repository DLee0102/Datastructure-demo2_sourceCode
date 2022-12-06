#pragma once
#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#define NUMBER 128
#include"char_code.h"
using namespace std;
void  Stat(char *s,int *w,int &num){
	cout<<"please enter the file's name:\n";
	char filename[50];
	char c;
	cin.getline(filename,50);
	ifstream ifs;
	ifs.open(filename,ios::in);
	if(!ifs.is_open()){
		cout<<"文件打开失败"<<endl;
		return;
	}
	for(int i = 0;i<NUMBER;i++){
		w[i] = 0;
	}
	//根据ASCⅡ码来计数 
	while(!ifs.eof()){
		if(ifs.good()){
			ifs>>noskipws>>c;
			w[c]++;
			s[c] = c;
		}
	}
	//按照前面的算法，最后的字符被算了两遍，因此要减去一次 
	if(ifs.eof()){
		ifs>>noskipws>>c;
		w[c]--;
	}
	//开始将数字按照顺序进行排序，将频数为0的放在末尾 
	int j = 0;
	int k[NUMBER]; 
	char q[NUMBER];
	for(int i = 0;i<NUMBER;i++){
		k[i] = 0;
	}
	for(int i = 0;i<NUMBER;i++){
		if(w[i]!=0){
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
	//将频数不为0的个数赋给num 
	num = j;
}


