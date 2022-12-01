#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            data=0;
            next=NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// for insertion at Head
void InsertAtHead(Node* &head, int d){
    // new node create
    Node* temp = new Node(d);
    temp->next=head;
    head = temp;
}

// for insertion at tail
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

// for display
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    //created a new node
    Node* node1 = new Node(10);
    // cout<< node1 -> data<<endl;
    // cout<< node1 -> next<<endl;

    // head pointer to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 500);
    print(head);


    return 0;
}