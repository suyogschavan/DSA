#include<iostream>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *Root;

class BST{
    public:
    void insert(int , struct node *);
    void display(struct node *);
};

void BST::insert(int d, struct node *root){
    struct node *newNode = new struct node;
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root==NULL)
    {
        Root=newNode;
    }
    else{
        if (root->data>newNode->data)
        {
            if(root->left==NULL)
            root->left = newNode;
            else
            insert(newNode->data, root->left);
        }else{
            if (root->data<newNode->data)   
            {
                if(root->right==NULL)
                root->right = newNode;
                else
                insert(newNode->data, root->right);
            }
        }
        
    }
    
}

void BST::display(struct node *root){
    if(root==NULL)
        return;
    display(root->left);
    cout<<root->data<<" ";
    display(root->right);
}

int main(){
    BST b;
    b.insert(20, Root);
    b.insert(10, Root);
    b.insert(30, Root);
    b.insert(5, Root);
    b.insert(3, Root);
    b.insert(70, Root);
    b.insert(100, Root);

    b.display(Root);
}