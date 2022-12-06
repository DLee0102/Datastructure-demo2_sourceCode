//
// Created by 浮生似流年 on 2022/11/29.
//

#ifndef MAIN_CPP_LEAFNODE_H
#define MAIN_CPP_LEAFNODE_H


#include "HuffNode.h"
#include "FreqPair.cpp"

template <class Elem>
class LeafNode: public HuffNode<Elem> {
private:
    FreqPair<Elem> *it;
public:
    LeafNode(Elem val, int freq);
    int weight() ;
    bool isLeaf() ;
    FreqPair<Elem>* val();
};



#endif //MAIN_CPP_LEAFNODE_H
