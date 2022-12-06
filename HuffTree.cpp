//
// Created by 浮生似流年 on 2022/11/29.
//
#pragma once
#include<iostream>
#include <cwchar>
#include "HuffTree.h"

using namespace std;

template<class Elem>
void HuffTree<Elem>::printhelp(HuffNode<Elem>* subroot, int level)const{
    FreqPair<Elem>* s1;
    if(subroot==NULL) {return;}
    if(subroot->isLeaf()) {
        for(int i=0;i<level;i++) {cout << "*";}
        cout << "Leaf: ";
        s1 = ((LeafNode<Elem>*)subroot)->val();
        cout << s1->val() << " " << s1->weight() << endl;
    } else {
        printhelp(((IntlNode<Elem>*)subroot)->left(), level + 1);   //打印左树
        for (int i=0;i<level;i++) {cout << "*";}    //打印内部节点
        cout << "Internal: ";
        cout << ((IntlNode<Elem>*)subroot)->weight() << endl;
        printhelp(((IntlNode<Elem>*)subroot)->right(), level + 1); //打印右树
    }
}
template<class Elem>
HuffTree<Elem>::HuffTree(Elem val, int freq) {
    myroot = new LeafNode<Elem>(val, freq);
}
template<class Elem>
HuffTree<Elem>::HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r) {
myroot = new IntlNode<Elem>(l->root(),r->root());
}
template<class Elem>
HuffTree<Elem>::~HuffTree() {
    clearhelp(myroot);
}
template<class Elem>
void HuffTree<Elem>::clear() {
    clearhelp(myroot);
    myroot = NULL;
}
template<class Elem>
void HuffTree<Elem>::clearhelp(HuffNode<Elem>* root){
    if (root == NULL) {return;}
    if (root->isLeaf()) {
        delete root;
    } else {
        clearhelp(((IntlNode<Elem>*)root)->left());
        clearhelp(((IntlNode<Elem>*)root)->right());
    }
}
template<class Elem>
HuffNode<Elem>* HuffTree<Elem>::root() {return myroot;}
template<class Elem>
int HuffTree<Elem>::weight() {return myroot->weight();}
template<class Elem>
void HuffTree<Elem>::print() const {
    if (myroot == NULL) {
        cout << "The HuffTree is empty.\n";
    } else {
        printhelp(myroot, 0);
    }
}