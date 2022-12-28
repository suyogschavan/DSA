#include <iostream>
#include <string>
using namespace std;
class publication
{
protected:
    string title;
    float price;

public:
    publication()
    {
        title = " ";
        price = 0;
    }
    publication(string t, float p)
    {
        title = t;
        price = p;
    }
};
class book : public publication
{
public:
    int pagecount;

    book()
    {
        pagecount = 0;
    }
    // After : base class constructor is called
    book(string t, float p, int pc) : publication(t, p)
    {

        pagecount = pc;
    }

    void display()
    {
        cout << "title :" << title << endl;
        cout << "Price: " << price << endl;
        cout << "Pagecount :" << pagecount << endl;
    }
};

class CD : public publication
{
    float time;

public:
    CD()
    {
        time = 0.0;
    }
    // After : base class constructor is called
    CD(string t, float p, float tim) : publication(t, p)
    {
        time = tim;
    }

    void display()
    {
        cout << "title :" << title << endl;
        cout << "Price: " << price << endl;
        cout << "time in minutes :" << time << endl;
    }
};
int main()
{
    cout << endl
         << "Book data" << endl;
try
{   
    book b("48 Laws of Power", 5000, 500);
    if(b.pagecount == 0){
        throw b.pagecount;
    }
    b.display();
}
catch(int b.pagecount)
{
    cout<<"Page count can't be zero..."<<endl;
    cout<<"replacing all data member values to zero."<<endl;
    publication p();
    book b();
    tape
}

    cout << endl
         << "CD Data" << endl;
    CD c("Rich Dad Poor Dad", 500, 120.5);
    c.display();
    return 0;
}