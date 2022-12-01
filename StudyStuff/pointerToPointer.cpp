#include<iostream>
using namespace std;

int main(){
     int a = 10;
     int *p;
     p = &a;

     cout<<*p<<endl; // will print the value of a

     int **q = &p;
     cout<<*q<<endl;  // will print the value of p
     cout<<**q<<endl; // will print the value of a

     return 0;
}