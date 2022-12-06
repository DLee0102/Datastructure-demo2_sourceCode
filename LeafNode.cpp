//
// Created by 浮生似流年 on 2022/11/29.
//

#include "LeafNode.h"
template <class Elem>
LeafNode<Elem>::LeafNode(Elem val, int freq) {it = new FreqPair<Elem>(val, freq);}
template <class Elem>
int LeafNode<Elem>::weight() {return it -> weight();}
template <class Elem>
bool LeafNode<Elem>::isLeaf() {return true;}
template <class Elem>
FreqPair<Elem>* LeafNode<Elem>::val() {return it;}