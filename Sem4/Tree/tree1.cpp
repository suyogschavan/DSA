#include<iostream>
#include<malloc.h>
using namespace std;

struct treenode{
    int data;
    struct treenode *Lnode, *Rnode;
};

struct treenode *root;

int getData(){
    int d;
    cout<<"Enter the data "<<endl;
    cin>>d;
    return d;
}
void CreateOneNode(){
    struct treenode *newNode;
    newNode=(struct treenode*)malloc(sizeof(struct treenode));
    newNode->data=getData();
    newNode->Lnode=NULL;
    newNode->Rnode=NULL;
    // root allocation
    root = newNode;
}

void Insertion(){
    struct treenode *newNode, *temp;
    newNode = (struct treenode*)malloc(sizeof(struct treenode));
    int ch;
    cout<<"Where you wan't to insert ?"<<endl;
    cout<<"1. for Left"<<endl;
    cout<<"2. for Right"<<endl;
    cin>>ch;
    newNode->data = getData();
    temp = root;
    if(ch==1){
        if(temp==NULL)
            cout<<"Tree not created yet."<<endl;
        else{
            if(temp->Lnode==NULL)
                temp->Lnode = newNode;
            else
                temp = temp->Lnode;     
        }
    }else if(ch==2){
        if(temp==NULL)
            cout<<"Tree not created yet."<<endl;
        else{
            if(temp->Rnode==NULL)
                temp->Rnode = newNode;
            else
                temp = temp->Rnode;     
        }
    }
}

void displayTree(){
    struct treenode *temp;
    temp=root;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        if(temp->Lnode==NULL)
        temp = temp->Rnode;
        else if(temp->Rnode == NULL)
        temp = temp->Lnode;
    }
}

int main(){
    CreateOneNode();
    displayTree();
    Insertion();
    displayTree();
}

