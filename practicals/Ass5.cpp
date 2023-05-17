#include<iostream>
#include<climits>
using namespace std;
class TreeNode
{
private:
    int data;
    TreeNode *left;
    TreeNode *right;
    bool leftThread;
    bool rightThread;
public:
    TreeNode()
    {
        data=0;
        left=NULL;
        right=NULL;
        leftThread=true;
        rightThread=true;
    }
    TreeNode(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
        leftThread=true;
        rightThread=true;
    }

    friend class inorderedTBST;
};
class inorderedTBST
{
private:
    TreeNode *root;
    TreeNode *dummyNode;
public:
    inorderedTBST()
    {
       root=NULL;
       dummyNode=NULL; 
    }

    void create_TBST()
    {
        int element;
        cout<<" Enter the TreeNode data : ";
        cin>>element;
        TreeNode *newNode=new TreeNode(element);
        if(root==NULL)
        {
            root=newNode;

            dummyNode=new TreeNode(INT_MIN);
            dummyNode->left=root;
            dummyNode->leftThread=false;
            dummyNode->right=dummyNode;
            dummyNode->rightThread=false;

            root->left=dummyNode;
            root->leftThread=true;
            root->right=dummyNode;
            root->rightThread=true;
        }
        else
        {
            TreeNode *current=root;
            while(1)
            {
                if(newNode->data < current->data)
                {
                    if(current->leftThread==false)
                    {
                        current=current->left;
                    }
                    else
                    {
                        break;
                    }
                }
                else if(current->data < newNode->data)
                {
                    if(current->rightThread==false)
                    {
                        current=current->right;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if(newNode->data < current->data)
            {
                newNode->left=current->left;
                newNode->leftThread=true;
                newNode->right=current;
                newNode->rightThread=true;

                current->left=newNode;
                current->leftThread=false;
            }
            else if(current->data < newNode->data)
            {
                newNode->left=current;
                newNode->leftThread=true;
                newNode->right=current->right;
                newNode->rightThread=true;

                current->right=newNode;
                current->rightThread=false;
            }
        }
    }

    TreeNode* findSuccessor(TreeNode* current)
    {
        if(current->rightThread==true)
        {
            return current->right;
        }
        else
        {
            current=current->right;
            while(current->leftThread==false)
            {
                current=current->left;
            }
            return current;
        }
    }
    void Inorder(TreeNode* current)
    {
        if(current==NULL)
        {
            cout<<endl;
            cout<<" The is NO Inordered Threaded Binary Search Tree created yet !! "<<endl;
            return ;
        }

        while(current->leftThread==false)
        {
            current=current->left;
        }

        while(current!=dummyNode)
        {
            cout<<current->data<<" ";
            current=findSuccessor(current);
        }
    }
    void Inorder()
    {
        TreeNode *current=root;
        cout<<endl;
        cout<<" Displaying the Inorder traversal of the Inordered Threaded Binary Search Tree (TBST) : ";
        Inorder(current);
        cout<<endl;
        return ;
    }

    void Preorder(TreeNode* current)
    {
        if(current==NULL)
        {
            cout<<endl;
            cout<<" The is NO Inordered Threaded Binary Search Tree created yet !! "<<endl;
            return ;
        }
        else
        {
            cout<<current->data<<" ";
            bool flag=false;

            while(current!=dummyNode)
            {
                while((current->leftThread==false) && (flag==false))
                {
                    current=current->left;
                    cout<<current->data<<" ";
                }

                if(current->rightThread==false)
                {
                    current=current->right;
                    cout<<current->data<<" ";
                    flag=false;
                }
                else
                {
                    current=current->right;
                    flag=true;
                }
            }
        }
    }
    void Preorder()
    {
        TreeNode *current=root;
        cout<<endl;
        cout<<" Displaying the Preorder traversal of the Inordered Threaded Binary Search Tree (TBST) : ";
        Preorder(current);
        cout<<endl;
        return ;
    }
};
int main()
{
    inorderedTBST obj;
    int option;
    do
    {
        cout<<endl;
        cout<<" -------------------------------- Menu -------------------------------- "<<endl;
        cout<<" 1. Create an Inordered Threaded Binary Search Tree (TBST) "<<endl;
        cout<<" 2. Display the Inorder traversal of Inordered Threaded Binary Search Tree (TBST) "<<endl;
        cout<<" 3. Exit "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        switch(option)
        {
            case 1:
                obj.create_TBST();
                break;
            case 2:
                obj.Inorder();
                break;       
        }
        cout<<endl;
    }while(option>=1 && option<=2);
    return 0;
}