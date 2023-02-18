#include<iostream>
using namespace std;

class Complex{
    public:
    float r, i;

    Complex(){
        r=0;
        i=0;
    }
    Complex(float r, float i){
        this->r=r;
        this->i=i;
    }

    // + operator overloading
    Complex operator +(Complex c){
        Complex temp;
        temp.r = r + c.r;
        temp.i = i + c.i;
        return temp;
    }

    // * operatoor overloading
    Complex operator *(Complex c){
        Complex temp;
        temp.r = r * c.r;
        temp.i = i * c.i;
        return temp;
    }
    friend istream &operator >>(istream &, Complex &);
    friend ostream &operator <<(ostream &, Complex &);
};

istream &operator >>(istream &is, Complex &c){
    cout<<"\nEnter the second Complex number : ";
    cout<<"\nEnter the real number: ";
    is>>c.r;
    cout<<"\nEnter the imaginary number: ";
    is>>c.i;
    return is;
}

ostream &operator <<(ostream &os, Complex &c){
    os<<c.r<<"+"<<c.i<<"i";
    return os;
}

int main(){
    Complex c1(4, 5), c2, c4, c3;
    cout<<"\nThe first complex number is : "<<c1;
    cin>>c2;

    // Addition
    c3 = c1+c2;
    cout<<"\nThe addition of "<<c1<< " and "<<c2<<" is: "<<c3;
    
    // Multiplication
    c4 = c1*c2;
    cout<<"\nThe multiplication of "<<c1<< " and "<<c2<<" is: "<<c4;
}
