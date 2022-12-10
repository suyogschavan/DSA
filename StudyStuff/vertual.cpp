#include<iostream>
using namespace std;

class Base{
    public:
    virtual void print(){
        cout<<"this is BASE class"<<endl;
    }

};

class Derived: public Base{
    public:
    void print(){
        cout<<"This is DERIVED class"<<endl;
    }
};

int main(){
    Base *basePTR;
    Derived d;
    basePTR = &d;
    basePTR ->print();
}