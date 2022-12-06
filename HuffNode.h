//
// Created by 浮生似流年 on 2022/11/29.
//

#ifndef MAIN_CPP_HUFFNODE_H
#define MAIN_CPP_HUFFNODE_H

template <class Elem>
class HuffNode {


    public:
        /**
         * @brief 虚函数
         *
         */
        virtual int weight() = 0;
        virtual bool isLeaf() = 0;

};


#endif //MAIN_CPP_HUFFNODE_H
