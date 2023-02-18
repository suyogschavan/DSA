#include<iostream>
using namespace std;

class Complex{
    public:
    float realp, imagp;

    Complex(){
        realp = 0;
        imagp = 0;
    }
    Complex(float x, float y){
        realp = x;
        imagp = y;
    }

    Complex operator+(Complex c){
        Complex temp;
        temp.realp = realp + c.realp;
        temp.imagp = imagp + c.imagp;
        return temp;
    }

    Complex operator*(Complex c){
        Complex temp;
        temp.realp = realp * c.realp;
        temp.imagp = imagp * c.imagp;
        return temp;
    }

    friend istream &operator>>(Complex &, istream &);
    friend ostream &operator<<(Complex &, ostream &);
};

istream &operator>>(Complex &c, istream &i){
    cout<<"Enter the real part: ";
    i>>c.realp;
    cout<<"Enter the imaginary part: ";
    i>>c.imagp;
    return i;
}

ostream &operator<<(Complex &c, ostream &o){
    o<<c.realp<<"+"<<c.imagp<<"i"<<endl;
    return o;
}

int main(){
    Complex c(43, 5);
    Complex c2;
    Complex add;
    Complex mult;

    cout<<"Complex no. 1 is: "<<c;
    // cin>>c2;
    // add = c+c2;
    // mult = c*c2;

    // cout<<add<<endl;
    // cout<<mult<<endl;
}