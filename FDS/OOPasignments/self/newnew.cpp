// #include<iostream>
// using namespace std;

// class base{
//     public:
//     virtual void display(){
//         cout<<"Display function from base class"<<endl;
//     }
// };

// class derived:public base{
//     public:
//     void display(){
//         cout<<"Display function from derived class"<<endl;
//     }
// };

// int main(){
//     derived d;
//     d.display();

//     // base b;
//     // b.display();
// }

#include <iostream>

using namespace std;

class parent_class

{

public:
    void print()

    {

        cout << "\nThis is print() method"

                " of BaseClass";
    }
};

class derived_class : public parent_class

{

public:
    // Function Overriding - new definition of

    // print method of base class

    void print()

    {

        cout << "\nThis is print() method"

                " of the Derived Class";
    }
};

// Driver code

int main()

{

    derived_class obj;

    obj.print();
}