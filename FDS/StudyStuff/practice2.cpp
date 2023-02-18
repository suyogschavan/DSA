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
        this->i = i;
        this->r = r;
    }

    //+ operator overloading
    Complex operator +(Complex c){
        Complex temp;
        temp.i = i + c.i;
        temp.r = r + c.r;
        return temp;
    }

    //* operator overloading
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
    cout<<"\nEnter the second Complex no.\n Enter the Real number: ";
    is>>c.r;
    cout<<"\nEnter the imaginary No. : ";
    is>>c.i;
    return is;
}

ostream &operator <<(ostream &os, Complex &c){
    os<<c.r<<"+"<<c.i<<"i";
    return os;
}

int main(){

    Complex c1(50, 30), c2, c3, c4;

    cout<<"First complex no. is: "<<c1;
    cin>>c2;

    cout<<"\nAddition of "<<c1<<" and "<<c2<<" is : ";
    c3 = c1+c2;
    cout<<c3;

    cout<<"\nMultiplication of "<<c1<<" and "<<c2<<" is : ";
    c4 = c1*c2;
    cout<<c4;
    return 0;
}