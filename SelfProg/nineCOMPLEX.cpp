#include<iostream>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;

    stack(int size){
        this->size=size;
        arr = new int[size];
        top=-1;
    }

    void push(int element){
        if (top==size-1)
        {
            cout<<"Stack overflow"<<endl;
        }else{
            top++;
            arr[top]=element;
        }
        
    }

    void pop(){
        if (top==-1)
        {
            cout<<"Stack underflow"<<endl;
        }else{
            top--;
        }
        
    }


    int peek(){
        if(top >= 0){
            return arr[top];
        }else
        {
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        
        
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }else
        {
            return false;
        }
        
    }
};

int main(){
    // stack st(5);
    // st.push(22);
    // st.push(33);
    // st.push(44);
    // st.push(55);
    
    // cout<<st.peek()<<endl;

    // st.pop();
    // cout<<st.peek()<<endl;

    stack s(10);
    char expression[20];
    cout<<"Paranthesis checker"<<endl;
    cout<<"Enter the expression: ";
    cin>>expression;
    int i, choice;
    if (expression[i]==')'||expression[i]==']'||expression[i]=='}')
        {
            cout<<"Invalid Expression..."<<endl;
            return 0;
        }
    while (expression[i]!='\0')
    {
        
        
        switch (expression[i])
        {
        case '(':
            s.push('(');
            break;
        case '[':
            s.push('[');
            break;
        case '{':
            s.push('{');
            break;
        case ')':s.pop();break;
        case ']':s.pop();break;
        case '}':s.pop();break;
        }
        i++;
    }

    if (s.isEmpty())
    {
        cout<<"Expression is VALID"<<endl;
    }else
    {
        cout<<"Expression is INVALID"<<endl;
    }
    
    
    
    
}