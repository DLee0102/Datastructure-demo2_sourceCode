#include<iostream>

using namespace std;

template <class Elem>
class FreqPair{
    private:
        Elem symbol;
        int freq;
    public:
    FreqPair(Elem s, int f) {symbol = s; freq = f;}
    int weight() {return freq;}
    Elem val() {return symbol;}
};

/**
 * @brief 变长节点
 * 
 * @tparam Elem 
 */
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
template <class Elem>
class LeafNode: public HuffNode<Elem> {
    private:
        FreqPair<Elem> *it;
    public:
        LeafNode(Elem val, int freq) {it = new FreqPair<Elem>(val, freq);}
        int weight() {return it -> weight();}
        bool isLeaf() {return true;}
        FreqPair<Elem>* val() {return it;}
};
template <class Elem>
class IntINode: public HuffNode<Elem> {
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
        IntINode(HuffNode<Elem>* l, HuffNode<Elem>* r) {
            wgt = l->weight() + r -> weight();
            lc = l;
            rc = r;
        }
        int weight() {return wgt;}
        bool isLeaf() {return false;}
        HuffNode<Elem>* left() {return lc;}
        void setLeft(HuffNode<Elem>* l) {lc = (HuffNode<Elem>*)l;}
        HuffNode<Elem>* right() {return rc;}
        void setRight(HuffNode<Elem>* r) {rc = (HuffNode<Elem>*)r;}
};


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
        void printhelp(HuffNode<Elem>* subroot, int level)const{
            FreqPair<Elem>* s1;
            if(subroot==NULL) {return;}
            if(subroot->isLeaf()) {
                for(int i=0;i<level;i++) {cout << "*";}
                cout << "Leaf: ";
                s1 = ((LeafNode<Elem>*)subroot)->val();
                cout << s1->val() << " " << s1->weight() << endl;
            } else {
                printhelp(((IntINode<Elem>*)subroot)->left(), level + 1);   //打印左树
                for (int i=0;i<level;i++) {cout << "*";}    //打印内部节点
                cout << "Internal";
                cout << ((IntINode<Elem>*)subroot)->weight() << endl;
                printhelp(((IntINode<Elem>*)subroot)->right(), level + 1); //打印右树
            }
        }
    
    public:
        HuffTree(Elem val, int freq) {
            myroot = new LeafNode<Elem>(val, freq);
        }
        HuffTree(HuffTree<Elem>* l, HuffTree<Elem>* r) {
            myroot = new IntINode<Elem>(l->root(), r->root());
        }

        ~HuffTree() {
            clearhelp(myroot);
        }

        void clear() {
            clearhelp(myroot);
            myroot = NULL;
        }

        void clearhelp(HuffNode<Elem>* root){
            if (root == NULL) {return;}
            if (root->isLeaf()) {
                delete root;
            } else {
                clearhelp(((IntINode<Elem>*)root)->left());
                clearhelp(((IntINode<Elem>*)root)->right());
            }
        }

        HuffNode<Elem>* root() {return myroot;}
        int weight() {return myroot->weight();}
        void print() const {
            if (myroot == NULL) {
                cout << "The HuffTree is empty.\n";
            } else {
                printhelp(myroot, 0);
            }
        }

};



int main(){
    HuffTree<int>* t = new HuffTree<int>(1, 1);
    t->print();
}