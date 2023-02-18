#include<iostream>
using namespace std;

class turm{
    int coeff;
    int exp;
};

class poly{
    public:
    int n;
    turm *t;
};

int main(){
    poly p;
    cout<<"Enter the no. of non zero turn: ";
    cin>>p.n;

    p.t = new turm[p.n];
    cout<<"Enter polynomial terms: "<<endl;
    for (int i=0, i<p.n;i++){
        cout<<"Term no"<<i+1<<" ";
        cin>>&p.t[i].coeff, &p.t[i].exp;
    }
}