#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Record{
    public:
    string roll;
    string name;

    void accept(){
        cout<<"Enter the roll no: ";
        cin>>this->roll;
        cout<<"Enter the name: ";
        cin>>this->name;
    }
    friend void display(Record r);
};

    void display(Record r){
        cout<<"Roll no. "<<r.roll<<"\nName: "<<r.name<<endl;
    }
int main(){

    Record r;
    fstream f, in;

    int n;
    cout<<"How many student you wan't to Enter in record?"<<endl;
    cin>>n;

    f.open("AssignmentNo4.txt", ios::out);
    while (n!=0)
    {
        r.accept();
        f<<r.roll<<endl;
        f<<r.name<<endl;
        n--;
    }
    f.close();

    in.open("AssignmentNo4.txt", ios::in);
    while (in.eof()==0)
    {
        getline(in, r.roll);
        getline(in, r.name);
        display(r);
    }
    
    
    in.close();

    

    return 0;
}