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
    complex operator+(complex &); // for addition of two complex nos
    complex operator*(complex &); // for multiplication of two complex nos
    complex(float, float);        // parameterized constructor
    friend istream &operator>>(istream &, complex &);
    friend ostream &operator<<(ostream &, complex &);
};
complex::complex(float x, float y) // parameterized constructor definition
{
    realp = x;
    imagp = y;
}
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
complex complex::operator+(complex &c)
{
    complex temp;
    temp.realp = realp + c.realp;
    temp.imagp = imagp + c.imagp;
    return temp;
}
// function to multiply two complex nos
complex complex::operator*(complex &c)
{
    complex mul;
    mul.realp = (realp * c.realp) - (imagp * c.imagp);
    mul.imagp = (imagp * c.realp) + (realp * c.imagp);
    return mul;
}
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
    cout<<"\n";
    return 0;
}