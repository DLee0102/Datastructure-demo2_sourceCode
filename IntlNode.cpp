//
// Created by 浮生似流年 on 2022/11/29.
//

#include "IntlNode.h"
template <class Elem>
        IntlNode<Elem>::IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r) {
                wgt = l->weight() + r->weight();
                lc = l;
                rc = r;
        }
template <class Elem>
        int IntlNode<Elem>::weight() {return wgt;}
template <class Elem>
        bool IntlNode<Elem>::isLeaf() {return false;}
template <class Elem>
        HuffNode<Elem>* IntlNode<Elem>::left() {return lc;}
template <class Elem>
        void IntlNode<Elem>::setLeft(HuffNode<Elem>* l) {lc = (HuffNode<Elem>*)l;}
template <class Elem>
        HuffNode<Elem>* IntlNode<Elem>::right() {return rc;}
template <class Elem>
        void IntlNode<Elem>::setRight(HuffNode<Elem>* r) {rc = (HuffNode<Elem>*)r;}