//
// Created by 浮生似流年 on 2022/12/1.
//

#ifndef MAIN_CPP_MINHEAP_H
#define MAIN_CPP_MINHEAP_H
#define NUMBER 128
#include <iostream>
#include "HuffTree.cpp"
using namespace std;

template<class Elem>
class minHeap {
private:
    HuffTree<Elem>* Heap[NUMBER];
    int maxSize;
    int size;
    void siftDown(int);
public:
    minHeap(HuffTree<Elem>* h[],int num,int max){
        size = num;
        maxSize = max;
        for (int i = 0; i < num; ++i) {
            Heap[i] = h[i];
        }

    }
    int heapSize()const {
        return size;
    }

    bool isLeaf(int pos){
        return (pos>=size/2)&&(pos<size);
    }

    int leftChild(int pos)const{
        return 2*pos+1;
    }
    int rightChild(int pos)const{
        return 2*pos+2;
    }
    int parent(int pos)const{
        return (pos-1)/2;
    }
    void print()const{
        for (int i = 0; i < size; ++i) {
            cout<<Heap[i]->weight()<<" ";
        }
        cout<<endl;
    }

    void buildHeap();
    HuffTree<Elem>* removeFirst();
    HuffTree<Elem>* remove(int pos);
    bool insert(HuffTree<Elem>* e);

};


#endif //MAIN_CPP_MINHEAP_H
