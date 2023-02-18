#include <iostream>
#include <string.h> // header file declares a set of functions to work strings.
using namespace std;

class db
{
  int roll;
  char name[20];
  char Class[10];
  char Div[10];
  char dob[12];
  char bg[5], city[10];
  char phone[12], license[12];

public:
  static int stdno;   // declaration of static variable
  static void count() // defination of static function
  {
    cout << "\n No.of objects created: " << stdno;
  }

  db() // default constructor
  {
    roll = 7;
    strcpy(name, "Sachin");
    strcpy(Class, "SE");
    strcpy(Div, "A");
    strcpy(dob, "13/08/1992");
    strcpy(bg, "B+");
    strcpy(city, "Pune");
    strcpy(phone, "9123456789");
    strcpy(license, "A1010");
    ++stdno;
  }
  void getdata() // defining member function
  {
    cout << "\n\nEnter:name,roll,Class,Div,Dob,bg,city,phone,license \n\n";
    cin >> name >> roll >> Class >> Div >> dob >> bg >> city >> phone >> license;
  }
  friend void display(db d); // declaration of friend function

  ~db() // destructor
  {
    cout << "\n\n"
         << this->name << "(Object) is destroyed!\n";
  }
};

void display(db d) // defination of friend function
{
  cout << "\n Name:" << d.name;
  cout << "\n Roll_No:" << d.roll;
  cout << "\n Class:" << d.Class;
  cout << "\n Div:" << d.Div;
  cout << "\n DOB:" << d.dob;
  cout << "\n Blood group:" << d.bg;
  cout << "\n City:" << d.city;
  cout << "\n Phone_No:" << d.phone;
  cout << " \n Liacense_No:" << d.license;
}
int db::stdno; // Define static data member stdno outside the class;

int main()
{
  int n, i;
  db d1, *ptr[5];
  cout << "\nDefault values:";
  display(d1);

  d1.getdata();
  display(d1);

  cout << "\nHow many objects u want to create?:";
  cin >> n;
  for (i = 0; i < n; i++)
  {
    ptr[i] = new db(); // new operator use to dynamic memory(run time) allocation
    ptr[i]->getdata();
  }
  cout << "\n"
       << "name"
       << "roll"
       << "Class"
       << "Div"
       << "dob"
       << "bg"
       << "contact"
       << "phone"
       << "license";
  for (i = 0; i < n; i++)
    display(*ptr[i]);
  db::count(); // calling of static function

  for (i = 0; i < n; i++)
  {
    delete (ptr[i]); // delete operator use to deallocation of memory
  }
  cout << "\nObjects deleted!";
}