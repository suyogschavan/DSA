#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;
    int i=0;
    char exp[20], ch;
    cout<<"\nEnter the expression to check whether it is in well form or not: ";
    cin>>exp;

    if ((exp[0]==')' || exp[0]==']' || exp[0]=='}'))
    {
        cout<<"\nEnvalid Expression.......\n";
        return 0;
    }else
    {
        while(exp[i]!='\0'){
            ch=exp[i];
            switch (ch)
            {
            case '(': s.push(ch); break;
            case '[': s.push(ch); break;
            case '{': s.push(ch); break;
            case ')': s.pop(); break;
            case ']': s.pop(); break;
            case '}': s.pop(); break;
            }
            i++;
        }
    }
    
    if (s.empty())
    {
        cout<<"\nExpression is well parenthesised...\n";
    }
    else
    {
        cout<<"\nSorry !!! Invalid Expression or not in well parentesized.....\n";
    }
    return 0;
}