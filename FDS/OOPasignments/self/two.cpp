#include<iostream>
using namespace std;

class database{
    string name, bg, Insurance, address, dlno;
    int height, weight, dob, number, tel;
    public:
    database(){
        name, bg, Insurance, address, dlno = "\0";
        height, weight, dob, number, tel = 0;
        counter++;
    }

    static int counter;
    static void count(){
        cout<<"\nNo. of objects created: "<<counter;
    }
    
    void getData(){
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter the Date of birth: ";
        cin>>dob;
        cout<<"Enter the Blood Group: ";
        cin>>bg;
        cout<<"Enter the Height: ";
        cin>>height;
        cout<<"Enter the Weight: ";
        cin>>weight;
        cout<<"You have insurance policy?* ";
        cin>>Insurance;
        cout<<"Enter the number: ";
        cin>>number;
        cout<<"Enter the address: ";
        cin>>address;
        cout<<"Enter the driving licence no: ";
        cin>>dlno;
        counter++;
    }

    friend void displayData(database d);

    ~database(){
        cout<<this->name<<" Object Distructed."<<endl;
    }
};

int database::counter=0;

void displayData(database d){
    cout<<"Name: "<<d.name<<endl;
    cout<<"Date of Birth: "<<d.dob<<endl;
    cout<<"Blood Group: "<<d.bg<<endl;
    cout<<"Height: "<<d.height<<endl;
    cout<<"Weight: "<<d.weight<<endl;
    cout<<"Have insurance?: "<<d.Insurance<<endl;
    cout<<"Number: "<<d.number<<endl;
    cout<<"Address: "<<d.address<<endl;
    cout<<"Driving Licence no: "<<d.dlno<<endl;
    cout<<"\n"<<endl;
}

int main(){

    int n, i;
    database db, *ptr[5];
    displayData(db);

    cout<<"Enter the info of student: "<<endl;
    db.getData();

    cout<<"Displaying the information from database: "<<endl;
    displayData(db);

    cout<<"How many objects do you wan't to create? ";
    cin>>n;
    for ( i = 0; i < n; i++)
    {
        ptr[i] = new database();// new operator use to dynamic memory allocation
        ptr[i]->getData();
    }

    cout<<"\nDisplaying all the data from database: "<<endl;
    for ( i = 0; i < n; i++)
    {
        displayData(*ptr[i]);
    }

    database::count();  // calling the static function

    for(i=0; i<n; i++){
        delete (ptr[i]); // delete operator use to deallocation of memeory
    }
    cout<<"\nObjects deleted";

}
