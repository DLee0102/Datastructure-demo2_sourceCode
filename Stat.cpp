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
		cout<<"�ļ���ʧ��"<<endl;
		return;
	}
	for(int i = 0;i<NUMBER;i++){
		w[i] = 0;
	}
	//����ASC���������� 
	while(!ifs.eof()){
		if(ifs.good()){
			ifs>>noskipws>>c;
			w[c]++;
			s[c] = c;
		}
	}
	//����ǰ����㷨�������ַ����������飬���Ҫ��ȥһ�� 
	if(ifs.eof()){
		ifs>>noskipws>>c;
		w[c]--;
	}
	//��ʼ�����ְ���˳��������򣬽�Ƶ��Ϊ0�ķ���ĩβ 
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
	//��Ƶ����Ϊ0�ĸ�������num 
	num = j;
}


