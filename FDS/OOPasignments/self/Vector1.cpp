#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

class student{
    public:
    int roll;
    string name;
    int mob;

    bool operator==(const student &s){
        return(roll==s.roll);
    }

    friend ostream &operator <<(ostream &out, student &);
    friend istream &operator <<(istream &in, student &);

};

ostream & operator <<(ostream &out, student &s){
    out<<"\nRoll No.: "<<s.roll<<"\nName: "<<s.name<<"\nMobile No.: "<<s.mob<<"\n"<<endl;
    return out;
}

istream & operator >>(istream &in, student &s){
    cout<<"\nEnter the Roll no. of student: ";
    in>>s.roll;
    cout<<"\nEnter the name of student: ";
    in>>s.name;
    cout<<"\nEnter mobile no.: ";
    in>>s.mob;
    return in;
}

vector<student> read(){
    int n;
    student k;
    vector<student> j;
    cout<<"\nEnter Total no. of students: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        j.push_back(k);
    }
    return j;
}

void printfunction(student &k){
    cout<<k;
}

void print(vector<student> &j){
    for_each(j.begin(), j.end(), printfunction);
}

void search(vector<student> &j){
    student k;
    cout<<"\nEnter the Student roll no. to search: ";
    cin>>k.roll;
    // cout<<"\n\n\tRoll no.\t\tName\t\tDate of Birth";
    vector<student>::iterator p;
    p = find(j.begin(), j.end(), k);
    if(p!=j.end())
        cout<<*p;
    else
        cout<<"\nNot found"<<endl;
}

bool sort_func(student &x, student &y){
    return(x.roll<y.roll);
}

void sort(vector<student> &j){
    sort(j.begin(), j.end(), sort_func);
}

int main(){
    int ch;
    vector<student> s;
    do
    {
        cout<<"Enter the choice you wan't to do : "<<endl;
        cout<<"1. Create Record"<<endl;
        cout<<"2. Display Record"<<endl;
        cout<<"3. Search Record"<<endl;
        cout<<"4.Sort Record"<<endl;
        cout<<"0. Exit Menu"<<endl;
        cout<<"-------------------------------";
        cin>>ch;

        switch (ch)
        {
        case 1:
            s=read();
            break;
        case 2:
            print(s);
            break;
        case 3:
            search(s);
            break;
        case 4:
            sort(s);
            print(s);
            break;
        
        default:
            break;
        }
    } while (ch!=0);
    
}