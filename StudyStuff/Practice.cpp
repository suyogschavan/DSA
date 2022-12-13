#include<iostream>
using namespace std;

class Complex{
    public:
    float r, i;

    Complex(){
        r = 0;
        i = 0;
    }
    Complex(float r, float i){
        this->r = r;
        this->i = i;
    }

    Complex operator +(Complex c){
        Complex temp;
        temp.r = r+c.r;
        temp.i = i+c.i;
        return temp;
    }

    Complex operator *(Complex c){
        Complex temp;
        temp.r = r * c.r;
        temp.i = i * c.i;
        return temp;
    }
    
    friend istream &operator >>(istream &, Complex &);
    friend ostream &operator <<(ostream &, Complex &);

    void display(){
        cout<<r<<"+"<<i<<"i";
    }
};

istream &operator >>(istream &is, Complex &c){
    cout<<"Enter the 2nd Complex Number: \nEnter the real no.: ";
    is>>c.r;
    cout<<"Enter the imaginary no.: ";
    is>>c.i;
    return is;
}

ostream &operator <<(ostream &o, Complex &c){
    o<<c.r<<"+"<<c.i<<"i"<<endl;
    return o;
}

int main(){
    Complex c1(20, 30);
    Complex c2;
    Complex c3;
    Complex c4;

    cout<<"First Complex number : ";
    cout<<c1;
    cin>>c2;

    cout<<"Addition on two : ";
    c3 = c1+c2;
    cout<<c3;

    cout<<"Multiplication on two : ";
    c4 = c1*c2;
    cout<<c4;
}