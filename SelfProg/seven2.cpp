#include<iostream>
using namespace std;

class Node{
    public:
    int prn;
    string name;
    Node* next;

    Node(){
        prn=0;
        name="";
        next = NULL;
    }

    Node(int prn, string name){
        this->prn = prn;
        this -> name = name;
    }
};

class ssl{
    public:
    Node* head;

    ssl(){head=NULL;}
    ssl(Node *n){
        head=n;
    }

// 1. check if node exists using keyvalue
    Node* nodeExists(int prn){
        Node *temp = NULL;
        Node* ptr = head;
        while (ptr!=NULL)
        {
            if(ptr->prn==prn){
                temp=ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

// 2. Append a node to the list
    void insertAtEND(Node *n){
        if(nodeExists(n->prn)!=NULL){
            cout<<"Node already Exists with this PRN no."<<endl;
        }else{
            if(head==NULL){
                head = n;
                cout<<"Secretary Inserted!"<<endl;
            }
            else{
                Node *pointer = head;
                while(pointer->next!=NULL){
                    pointer = pointer->next;
                }
                pointer->next = n;
                cout<<"Secretary Inserted!"<<endl;
            }
        }
    }

    // 3. Prepend Node - attach a node at the start
    void insertAtStart(Node *n){
        if(nodeExists(n->prn)!=NULL){
            cout<<"Node already Exists with this PRN no."<<endl;
        }else{
           n->next = head;
           head=n;
           cout<<"President Inserted!"<<endl;
        }
    }

    // 4. Insert Node in between somewhere
    void insertBetween(Node *n){
        Node *pointer = head->next;
            n->next = pointer;
            head->next=n;
    }

    // 5. Delete node by PRN no.
    void deletebyPRN(int prn){
        if(head==NULL){
            cout<<"SSL is empty";

        }
        else if(head!=NULL){
            if(head->prn==prn){
                Node *n = head;
                head = head->next;
                free(n);
                cout<<"Node unlinked and DELETED with PRN no: "<<prn<<endl;
            }
            else{
                Node* temp=NULL;
                Node* prevptr = head;
                Node* currentptr = head->next;

                while(currentptr!=NULL){
                    if(currentptr->prn==prn){
                        temp = currentptr;
                        currentptr=NULL;
                    }else{
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp!=NULL)
                {
                    prevptr->next=temp->next;
                    free(temp);
                    cout<<"Node Deleted..."<<endl;
                    
                }
                else
                {
                    cout<<"Node doesn't exist with this PRN"<<endl;
                } 
            }
        }
    }

    // 6. display
    void display(){
        if (head==NULL)
        {
            cout<<"No nodes in ssl";

        }else
        {
            Node* temp = head;
            while (temp!=NULL)
            {
                cout<<"("<<temp->prn<<", "<<temp->name<<") --> ";
                temp = temp->next;
            }  
        }
    }

    void count(){
        Node* temp = head;
        int a;
        while (temp!=NULL)
        {
            temp=temp->next;
            a++;
        }
        cout<<"Total no. of members: "<<a<<endl;
        
    }

};

int main(){
    ssl s;
    int option, p;
    string n;
    do
    {
        cout<<"\nEnter the option: "<<endl;
        cout<<"1. Insert President"<<endl;
        cout<<"2. Insert Secretary"<<endl;
        cout<<"3. Insert Member"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Count"<<endl;
        cout<<"6. Delete by PRN"<<endl;


        cin>>option;
        Node *node= new Node();

        switch (option)
        {
        case 0:
            break;
        case 1:
            {cout<<"Enter the president PRN no.: ";
            cin>>p;
            cout<<"\nEnter the name of president: ";
            cin>>n;
            node->name=n;
            node->prn=p;
            s.insertAtStart(node);}
            break;
        case 2:
        {   cout<<"Enter the Secretary PRN no.: ";
            cin>>p;
            cout<<"\nEnter the name of Secretary: ";
            cin>>n;
            node->name=n;
            node->prn=p;
            s.insertAtEND(node);}
            break;
        case 3:
        {   cout<<"Enter the member's PRN no.: ";
            cin>>p;
            cout<<"\nEnter the name of member: ";
            cin>>n;
            node->name=n;
            node->prn=p;
            s.insertBetween(node);}
            break;
        case 4:s.display();
            break;
        case 5:s.count();
            break;
        case 6:
        {   cout<<"Enter the PRN no you wan't to delete: ";
            cin>>p;
            // node->prn=p;
            s.deletebyPRN(p);}
        default:
            break;
        }
    } while (option!=0);
    
}