#include<iostream>
#include<string>
using namespace std;

class publisher{
    public:
    string title;
    float price;

    publisher(){
        this->title="\0";
        this->price=0;
    }
    publisher(string t, float p){
        this->price = p;
        this->title = t;
    }

};

class book:public publisher{
    public:
    int pagecount;
    book():publisher(){pagecount=0;}
    book(string t, float p, int page):publisher(t, p){
        this->pagecount = page;
    }
    void display(){
        cout<<"BOOK's title: "<<this->title<<endl;
        cout<<"BOOK's price: "<<this->price<<endl;
        cout<<"BOOK's pages: "<<this->pagecount<<endl;
    }
};

class tape:public publisher{
    public:
    float time;
    tape():publisher(){this->time = 0;}
    tape(string t, float p, float tim):publisher(t, p){
        this->time = tim;
    }
    void display(){
        cout<<"TAPE's title: "<<this->title<<endl;
        cout<<"TAPE's price: "<<this->price<<endl;
        cout<<"TAPE's time in Min: "<<this->time<<endl;
    }
};
// GLOBAL
static string t;
static float p;
static int page;
static float t_min;

void getData(){
    cout<<"Enter the title : ";
    cin>>t;
    cout<<"Enter the price : ";
    cin>>p;
}

int main(){
    book b;
    tape obj_t;
    int ch;
    do{
        cout<<"\n----------MENU---------"<<endl;
        cout<<"1. to enter book's info"<<endl;
        cout<<"2. to enter tape's info"<<endl;
        cout<<"3. to view book's info"<<endl;
        cout<<"4. to view tape's info"<<endl;
        cout<<"0. for Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 1:getData();
            cout<<"Enter the page count: ";
            cin>>page;
            try
            {
                if(page==0)
                throw page;
                static b(t, p, page);
                cout<<"\nData entered successfully..."<<endl;
            }
            catch(int page)
            {
                cout<<"EXCEPTION: Pages cannot be zero."<<endl;
                cout<<"Initilizing all values to zero."<<endl;
                book b;
            }
            
            break;

            case 2:getData();
            cout<<"Enter the time in minute: ";
            cin>>t_min;
            try
            {
                if(t_min==0)
                throw t_min;
                static obj_t(t, p, t_min);
                cout<<"\nData Entered Succesfully..."<<endl;
            }
            catch(int t_min)
            {
                cout<<"EXCEPTION: Time cannot be zero."<<t_min<<endl;
                cout<<"Initilizing all values to zero."<<endl;
                tape obj_t;
            };
            
            break;

            case 3:
            b.display();
            break;
            
        }
    }while(ch!=0);
}