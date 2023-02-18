#include<iostream>
#include<fstream>
using namespace std;
int main(){
    char arr[100];
    cout<<"Enter your name and age: ";
    cin.getline(arr,100);

    ofstream myfile("suyog1.txt", ios::app); //ofstream for writing file
    myfile<<arr;
    myfile.close();
    cout<<"File write operations performed succesfully";

    cout<<"Reading started: "<<endl;
    ifstream objfile("suyog1.txt"); // ifstream for reading the file
    objfile.getline(arr, 100);
    cout<<"array content: "<<arr<<endl;
    cout<<"file read operation completed"<<endl;
    objfile.close();

    return 0;
}