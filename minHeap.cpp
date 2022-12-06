//
// Created by 浮生似流年 on 2022/12/1.
//



#include "minHeap.h"

using namespace std;
template<class Elem>
void minHeap<Elem>::siftDown(int pos) {
    while(!isLeaf(pos)){
        int lc = leftChild(pos);
        int rc = rightChild(pos);
        if((rc<size)&&(Heap[lc]->weight()>Heap[rc]->weight())){
            lc = rc;
        }
        if(Heap[pos]->weight() <= Heap[lc]->weight()) return;
        HuffTree<Elem>* t = Heap[pos];
        Heap[pos] = Heap[lc];
        Heap[lc] = t;
        pos = lc;
    }
    return;
}

template<class Elem>
void minHeap<Elem>::buildHeap() {
    for (int i = size/2-1; i >= 0; --i) {
        siftDown(i);
    }
}

template<class Elem>
HuffTree<Elem>* minHeap<Elem>::removeFirst() {
    if(size<=0){
        cout<<"Heap is empty"<<"test"<<endl;
        return 0;
    }
    size--;
    if(size != 0){
        HuffTree<Elem>* t = Heap[size];
        Heap[size] = Heap[0];
        Heap[0] = t;
        siftDown(0);
    }
    return Heap[size];

}

template<class Elem>
bool minHeap<Elem>::insert( HuffTree<Elem>* e) {
    if(size>=maxSize){
        cout<<"Heap is full"<<endl;
        return false;
    }
    int curr = size;
    Heap[curr] = e;
    size++;
    //用一个变量记录curr的父亲的位置
    int par = parent(curr);
    while(curr!=0 && (Heap[curr]->weight()<Heap[par]->weight())){
        HuffTree<Elem>* t = Heap[curr];
        Heap[curr] = Heap[parent(curr)];
        Heap[parent(curr)] = t;
        curr = parent(curr);
        par = parent(curr);
    }
    return true;
}