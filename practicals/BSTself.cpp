#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *Root = NULL;

class BST
{
public:
    void insertNewNode(struct node *temp, int data);
    void countNodes(struct node *temp);
    int minimum();
    bool search(int d);
};

void BST::insertNewNode(struct node *temp, int d)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = d;
    if (Root == NULL)
        Root = newNode;
    else
    {
        if (temp->data < d)
        {
            if (temp->right == NULL)
            {
                temp->right = newNode;
            }
            else
            {
                insertNewNode(temp->right, d);
            }
        }
        else
        {
            if (temp->left == NULL)
            {
                temp->left = newNode;
            }
            else
            {
                insertNewNode(temp->left, d);
            }
        }
    }
};

int count;
void BST::countNodes(struct node *temp)
{
    if (temp == NULL)
        return;
    countNodes(temp->left);
    count++;
    countNodes(temp->right);
};

int BST::minimum()
{
    struct node *temp;
    temp = Root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
};

bool BST::search(int d){
    
}


int main()
{
    BST bst;
    bst.insertNewNode(Root, 10);
    bst.insertNewNode(Root, 20);
    bst.insertNewNode(Root, 3);
    bst.insertNewNode(Root, 5);
    bst.insertNewNode(Root, 1);
    int mini = bst.minimum();
    cout << mini << endl;
    bst.countNodes(Root);
    cout<<count<<endl;
}