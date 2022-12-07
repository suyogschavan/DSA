#include<iostream>
using namespace std;

class node{
    public:
    int PRN;
    string name;
    node *next;

    node(){
        PRN = 0;
        name= "";
        next = NULL;
    }

    node(int PRN, string name){
        this->PRN = PRN;
        this->name = name;
        this -> next = NULL;
    }

};

void insertPresident(node* &head, int PRN, string name){

    node* temp = new node(PRN, name);
    temp->next=head;
    head = temp;
}

void insertSecretary(node* &tail, int PRN, string name){
    node* temp = new node(PRN, name);
    tail -> next = temp;
    tail = temp;
}

void display(node* &head){
    node *temp = head;
    while(temp!=NULL){
        if (temp==head) 
        {
            cout<<"PRESIDENT: ";
        }
        
        cout<<" PRN: "<<temp->PRN<<" \t Name: "<<temp->name<<temp->next;
        temp = temp->next;
    }
}

int main(){
    node* node1 = new node(118, "SUYOG");
    node* head = node1;
    display(head);
}