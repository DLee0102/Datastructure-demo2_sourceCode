#include<iostream>
#include<string>
#include<fstream> 
#include<stdio.h>
#define NUMBER 128
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
	while(!ifs.eof()){
		if(ifs.good()){
			ifs>>noskipws>>c;
			//cout<<c;
			w[c]++;
			s[c] = c;
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
int main(){
	int n = 0;
	char s[NUMBER];
	int w[NUMBER];
	Stat(s,w,n);
	for(int i = 0;i<n;i++){
		cout<<s[i];
		cout<<" ";
		cout<<w[i]<<endl;
	}
}

