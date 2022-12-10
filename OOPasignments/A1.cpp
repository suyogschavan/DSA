#include <iostream>
using namespace std;
class complex // class name complex is declared
{
    float realp, imagp;

public:
    complex() // default constructor
    {
        realp = 0;
        imagp = 0;
    }

    complex(float x, float y)
    {
        realp = x;
        imagp = y;
    }

    complex operator+(complex a)
    { // for addition of two complex nos
        complex temp;
        temp.realp = imagp + a.realp;
        temp.imagp = imagp + a.imagp;
        return temp;
    }

    complex operator*(complex a)
    { // for multiplication of two complex nos
        complex temp;
        temp.realp = imagp * a.realp;
        temp.imagp = imagp * a.imagp;
        return temp;
    }

    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, complex &);
};

// function to accept values of real and imag parts of complex no
istream &operator>>(istream &din, complex &c)
{
    cout << "Enter real part of complex number 2: ";
    din >> c.realp;
    cout << "\nEnter imaginary part of complex number 2: ";
    din >> c.imagp;
    return din;
}

// functions to display complex nos
ostream &operator<<(ostream &dout, complex &c)
{
    dout << c.realp << " + " << c.imagp << "i";
    dout << endl;
    return dout;
}
// function to add two complex nos

// function to multiply two complex nos

int main()
{
    complex c2, c3;
    complex c1(1.2, 2.2);
    cout << "Complex no 1 is:" << c1;
    cout << "Enter complex no 2:\n";
    cin >> c2;
    cout << "Complex number 1 is :";
    cout << c1;
    cout << "Complex number 2 is :";
    cout << c2;
    cout << "Complex number 3 is :";
    cout << c3;
    cout << "\nAddition of two complex numbers is: ";
    c3 = c1 + c2;
    cout << c3;
    cout << "\nMultiplication of two complex number is: ";
    c3 = c1 * c2;
    cout << c3; // display value of c3
    cout << "\n";
    return 0;
}

// #include<iostream>
// using namespace std;

// class Complex{
//     public:
//     int real, imag;

//     Complex(){
//         real = 0;
//         imag = 0;
//     }

//     complex(int a, int b){
//         real = a;
//         imag = b;
//     }

//     // + operator overloading
//     Complex operator+ (Complex c){
//         Complex temp;
//         temp.real = real+c.real;
//         temp.imag = imag+c.imag;
//         return temp;
//     }

//     // * operator overloading
//     Complex operator* (Complex c){
//         Complex temp;
//         temp.real = real * c.real;
//         temp.imag = imag * c.imag;
//         return temp;
//     }

//     // for display
//     void display(){
//         cout<<real<<" + "<<imag<<"i"<<endl;
//     }

// };

// int main(){

//     Complex c1, c2, sum, mult;
//     c1.complex(1, 4);
//     c2.complex(2, 5);

//     // for sum
//     sum = c1+c2;
//     sum.display();

//     // for multiplication
//     mult = c1 * c2;
//     mult.display();

//     return 0;
// }