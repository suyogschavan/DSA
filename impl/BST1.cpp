#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *Root;

class BST
{
public:
    BST()
    {
        Root = NULL;
    }

    void insert_new(int d, struct node *root)
    {
        struct node *newNode = new node;
        newNode->data = d;
        newNode->left = newNode->right = NULL;
        if (Root == NULL)
            Root = newNode;
        else
        {
            if (root->data > newNode->data)
            {
                if (root->left == NULL)
                    root->left = newNode;
                insert_new(newNode->data, root->left);
            }
            else
            {
                if (root->data < newNode->data)
                {
                    if (root->right == NULL)
                        root->right = newNode;
                    insert_new(newNode->data, root->right);
                }
            }
        }
    }

    void print_Tree(struct node *root)
    {
        if (root == NULL)
            return;
        print_Tree(root->left);
        cout << root->data << " ";
        print_Tree(root->right);
    }

    int rcount = 0;
    int lcount = 0;
    void right_longest(struct node *root)
    {
        if (root == NULL)
            return;
        rcount++;
        right_longest(root->right);
    }
    int minimum;
    void left_longest(struct node *root)
    {
        if (root == NULL)
            return;
        lcount++;
        minimum = root->data;
        left_longest(root->left);
    }
    int no_nodes_longest()
    {
        right_longest(Root);
        left_longest(Root);
        if (rcount > lcount)
            return rcount;
        else
            return lcount;
    }

    bool search(int d)
    {

        struct node *temp;
        temp = Root;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                return true;
            }
            else
            {
                if (temp->data > d)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return false;
    }
};

int main()
{
    BST b;
    b.insert_new(20, Root);
    b.insert_new(10, Root);
    b.insert_new(30, Root);
    b.insert_new(50, Root);
    b.insert_new(5, Root);
    b.insert_new(9, Root);
    b.insert_new(35, Root);
    b.insert_new(40, Root);

    b.print_Tree(Root);
    cout << b.no_nodes_longest() << endl;
    cout << b.minimum << endl;
    if (b.search(60))
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}