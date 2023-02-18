#include<iostream>
using namespace std;

class Complex{
    public:
    float i, r;

    Complex(){
        i = 0;
        r = 0;
    }

    Complex(float i, float r){
        this->r = r;
        this->i = i;
    }

    // +operator overloading
    Complex operator +(Complex c){
        Complex temp;
        temp.r = r + c.r;
        temp.i = i + c.i;
        return temp;
    }

    // *operator overloading
    Complex operator *(Complex c){
        Complex temp;
        temp.r = r * c.r;
        temp.i = i * c.i;
        return temp;
    }

    friend ostream &operator <<(ostream &, Complex &);
    friend istream &operator >>(istream &, Complex &);
};


ostream &operator <<(ostream &os, Complex &c){
    os<<c.r<<"+"<<c.i<<"i";
    return os;
}

istream &operator >>(istream &is, Complex &c){
    cout<<"\nEnter the second Complex no. \nEnter the real no.: ";
    is>>c.r;
    cout<<"Enter the imaginary no.: ";
    is>>c.i;

    return is;
}


int main(){
    Complex c2, c1(4, 5), c3, c4;
    cout<<"First Complex no is: "<<c1;
    cin>>c2;

    // Addition 
    c3=c1+c2;
    cout<<"Addition of "<<c1<< " and "<<c2<<" is: "<<c3;
    
    // multiplication 
    c4=c1*c2;
    cout<<"\nMultiplication of "<<c1<< " and "<<c2<<" is: "<<c4;

}