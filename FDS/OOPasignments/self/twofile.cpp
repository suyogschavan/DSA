// Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    
    char str[100];
    cout<<"Enter what you wan't to enter in your new file"<<endl;
    cin.getline(str, 100);

    ofstream obj("Suyog2.txt");
    // obj.write(str);
    obj<<str;
    obj.close();

}