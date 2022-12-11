#include<iostream>
using namespace std;

class parent{
    public:
    parent(){
        cout<<"Parent Constructor \n";
    }

    ~parent(){
        cout<<"Parent Destructor \n";
    }
};

class child:public parent{
    public:
    child(){
        cout<<"Child Constructor\n";
    }

    ~child(){
        cout<<"Child Distroctor\n";
    }
};

int main(){
    child c;
    return 0;
}