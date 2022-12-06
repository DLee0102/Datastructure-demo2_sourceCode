//
// Created by 浮生似流年 on 2022/11/29.
//

#ifndef MAIN_CPP_HUFFTREE_H
#define MAIN_CPP_HUFFTREE_H


#include "LeafNode.cpp"
#include "IntlNode.cpp"

template <class Elem>
class HuffTree{
private:
    HuffNode<Elem>* myroot;
    /**
     * @brief 中序遍历
     *
     * @param subroot
     * @param level
     */
    void printhelp(HuffNode<Elem>* subroot, int level)const;

public:
    HuffTree(Elem val, int freq) ;
    HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r) ;

    ~HuffTree();

    void clear() ;

    void clearhelp(HuffNode<Elem>* root);

    HuffNode<Elem>* root();
    int weight();
    void print() const ;

};

#endif //MAIN_CPP_HUFFTREE_H
