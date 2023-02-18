#include<iostream>
using namespace std;

int main(){
    
    int a=10;
    int *ptrA;
    ptrA = &a;

    // cout<<"Printing the address of A: "<<&a<<endl;
    // cout<<"Printing the pointer ptrA: "<<ptrA<<endl;
    // cout<<"Printing the *ptrA: "<<*ptrA<<endl;

    // we can also change the value of variable from pointer
    cout<<"Old Value of A: "<<a<<endl;
    // changing value from pointer
    *ptrA=50;
    // now printing
    cout<<"New value of A: "<<a<<endl;

    
    return 0;
}