#include<iostream>
using namespace std;

// void swap(int a, int b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a= 10;
    int b= 90;

    //swap(a, b); // pass by value // it is not gonna change.
    // to change, we need to create pointers of these variables.
    int *pa = &a;
    int *pb = &b;

    swap(pa, pb);
    cout<<"After swapping a: "<<a<<" and b: "<<b<<endl;
}