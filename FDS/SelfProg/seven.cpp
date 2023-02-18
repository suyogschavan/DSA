// # Singly Linked List
#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
    int PRN;
    string name;
    Node *next;

    Node()
    {
        PRN = 0;
        name = "";
        next = NULL;
    }
    Node(int PRN, string n)
    {
        this->PRN = PRN;
        this->name = n;
    }
};

void insertP(Node *&head, int p, string n)
{
    Node *temp = new Node(p, n);
    temp->next = head;
    head = temp;
}

void insertS(Node *&tail, int p, string n)
{
    Node *temp = new Node(p, n);
    tail->next = temp;
    tail = temp;
}

void insertM(Node *&head, int p, string n){
    Node *temp = new Node(p, n);
    Node *pointer = head->next;
    if (temp!=head && temp->next!=NULL)
    {
        temp->next=pointer;
        head->next=temp;
    }    
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp==head)
        {
            cout<<"President: ";
        }
        if (temp->next==NULL)
        {
            cout<<"Secretary: ";
        }
        cout << "PRN: " << temp->PRN << "\t| NAME: " << temp->name << "\n";
        temp = temp->next;
    }
}


int main()
{
    char ch;
    do
    {  
    cout<<"Enter the choise: \n1. Insert President\n2. Insert Secretery\n3. Insert Member"<<endl;
    cout<<"4. Display list"<<endl;
    int c;
    cin>>c;
    Node* node1;

    switch (c)
    {
    case 1:{string name;
        int PRN;
        cout<<"Enter the Name: ";
        cin>>name;
        cout<<"Enter PRN no.: ";
        cin>>PRN;
        insertP(node1, PRN, name);
        cout<<"President Inserted succesfully.!"<<endl;}
        break;

        case 2:{string name;
        int PRN;
        cout<<"Enter the Name: ";
        cin>>name;
        cout<<"Enter PRN no.: ";
        cin>>PRN;
        insertS(node1, PRN, name);
        cout<<"Secretary Inserted succesfully.!"<<endl;}
        break;

        case 3:
        {string name;
        int PRN;
        cout<<"Enter the Name: ";
        cin>>name;
        cout<<"Enter PRN no.: ";
        cin>>PRN;
        insertM(node1, PRN, name);
        cout<<"Member Inserted succesfully.!"<<endl;}
        break;

        case 4:display(node1);break;
    };
    cout<<"Do you wan't to Continue? \nY->Yes, \nN->No\n";
    cin>>ch;
    } while (ch=='y'|| ch=='Y');

}
