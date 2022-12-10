#include<iostream>
using namespace std;

class Complex{
    private:
    int real, imag;
    public:
    
    Complex(){
        real = 0;
        imag = 0;
    }
    
    Complex(int r, int i){
        real = r;
        imag = i;
    }

    void print(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

    Complex operator +(Complex c){
        Complex temp;
        temp.real = real+c.real;
        temp.imag = imag+c.imag;
        return temp;
    }

    Complex operator *(Complex d){
        Complex temp;
        temp.real = real * d.real;
        temp.imag = imag * d.imag;
        return temp;
    }

};

int main(){

    Complex c1(5, 4);
    Complex c2(2, 5);
    Complex add;
    Complex mult;

    add = c1+c2;
    mult = c1*c2;

    add.print();
    mult.print();
    return 0;
}