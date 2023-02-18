#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class file{
    public:
    void writeData();
    void readData();
};

void file::writeData(){
    string data;
    fstream obj;
    obj.open("Assignment.txt", ios::out);
    cout<<"Enter the data: ";
    getline(cin, data);
    obj<<data;
    obj.close();
}

void file::readData(){
    string data;
    fstream obj;
    obj.open("Assignment.txt", ios::in);
    getline(obj, data);
    cout<<data;
}

int main(){
    file f;
    f.writeData();
    f.readData();
}
