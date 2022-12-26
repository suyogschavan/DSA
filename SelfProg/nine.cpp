#include<iostream>
#include<stack>
using namespace std;

int main(){

    // Creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    // pop operation
    s.pop();

    // printing Top element
    cout<<"Printing top element"<<endl;
    cout<<s.top()<<endl;

    if (s.empty())
    {
        cout<<"Stack is Empty "<<endl;
    }else
    {
        cout<<"Stack is not Empty "<<endl;
    }
    
    cout<<"Size of stack is "<<s.size()<<endl;
    return 0;
}