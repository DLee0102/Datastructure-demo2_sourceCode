#include<iostream>

using namespace std;

class Fruit {
    public:
        int price = 10;
        char* name = "fruit";
        virtual char* getCata() = 0;

};

class Apple: public Fruit{
    public:
        int price = 20;
        char* cata = "Apple";
        char* getCata(){
            return cata;
        }
};

int main(){
    Fruit* a = new Apple();
    cout << a->name;
    cout << a->price;
    cout << a->getCata();
}