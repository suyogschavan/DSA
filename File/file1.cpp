#include<iostream>
#include<fstream>
using namespace std;

class File{
    public:
    string name, roll, address, div;

    File(){
        ofstream o("file.txt");
        o<<"Roll, Name, Address, Div";
        o.close();
    }

    void insert(){
        string n, r, a, d;
 
        cout<<"Enter the Roll no. of student: ";
        getline(cin, r);
        cout<<"Enter the name of student: ";
        getline(cin, n);
        cout<<"Enter the Div of student: ";
        getline(cin, d);
        cout<<"Enter the address of student: ";
        getline(cin, a);

        File f;
        f.name = n;
        f.address = a;
        f.div = d;
        f.roll = r;

        ofstream file("file.txt", ios::app);
        file<<"\n"<<f.roll<<", "<<f.name<<", "<<f.address<<", "<<f.div<<endl;
        file.close();
    }

    void search(){
        File s;
        fstream f;
        string name;
        cout<<"Enter the name of student you wan't to search: ";
        cin>>name;
        f.open("file.txt", ios::app | ios::out | ios::in);
        while(!f.eof()){
            f>>s.address;
            f>>s.name;
            f>>s.div;
            f>>s.roll;
            if (s.name == name)
            {
                cout<<"Details: "<<endl;
                cout<<s.roll<<endl;
                cout<<s.div<<endl;
                cout<<s.address<<endl;
            }
            
        }
    
    }

};

int main(){
    File f;
    f.insert();
}
