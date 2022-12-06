//
// Created by 浮生似流年 on 2022/11/29.
//

#ifndef MAIN_CPP_INTLNODE_H
#define MAIN_CPP_INTLNODE_H


#include "HuffNode.h"
template <class Elem>
        //继承父类要加public ，否则在派生类向基类转换时会出问题，具体参考csdn
class IntlNode:public HuffNode<Elem>{
        private:
            HuffNode<Elem>* lc;
            HuffNode<Elem>* rc;
            int wgt;
        public:
            /**
             * @brief Construct a new Int I Node object
             * 此处用到了多态，参数表是父类类型，传入的参数可以是任意子类，
             * 但由于赋给父类变量的子类实例的属性在「编译时」不可见，
             * 故设计了返回属性的函数来得到子类的属性值。
             *
             * @param l
             * @param r
             */
            IntlNode(HuffNode<Elem>* l, HuffNode<Elem>* r);
            int weight() ;
            bool isLeaf() ;
            HuffNode<Elem>* left() ;
            void setLeft(HuffNode<Elem>* l) ;
            HuffNode<Elem>* right() ;
            void setRight(HuffNode<Elem>* r) ;
};


#endif //MAIN_CPP_INTLNODE_H
