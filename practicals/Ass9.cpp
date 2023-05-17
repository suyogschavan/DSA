#include<iostream>
#include<string>
using namespace std;
class TreeNode
{
private:
    string keyword;
    string meaning;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode()
    {
        keyword=" ";
        meaning=" ";
        left=NULL;
        right=NULL;
    }
    TreeNode(string keyword,string meaning)
    {
        this->keyword=keyword;
        this->meaning=meaning;
        left=NULL;
        right=NULL;
    }

    friend class Dictionary;
};
class Dictionary
{
private:
    TreeNode *root;
public:
    Dictionary()
    {
        root=NULL;
    }

    void insert_word()
    {
        string keyword;
        cout<<" Enter the keyword : ";
        cin>>keyword;
        cin.ignore(100,'\n');
        string meaning;
        cout<<" Enter the meaning of "<<keyword<<" : ";
        getline(cin,meaning);
        TreeNode* newNode=new TreeNode(keyword,meaning);
        if(root==NULL)
        {
            root=newNode;
        }
        else
        {
            TreeNode *current=root;
            while(1)
            {
                if(newNode->keyword < current->keyword)
                {
                    if(current->left==NULL)
                    {
                        current->left=newNode;
                        break;
                    }
                    else
                    {
                        current=current->left;
                    }
                }
                else if(current->keyword < newNode->keyword)
                {
                    if(current->right==NULL)
                    {
                        current->right=newNode;
                        break;
                    }
                    else
                    {
                        current=current->right;
                    }
                }
            }
        }
        cout<<" The Keyword and it's Meaning inserted in Dictionary Successfully !! "<<endl;
    }

    void search_word()
    {
        if(root==NULL)
        {
            cout<<" The Dictionary doesn't contains any keywords yet. "<<endl;
            return ;
        }

        string keyword;
        cout<<" Enter the keyword whose meaning you want to search in Dictionary : ";
        cin>>keyword;
        int comparisons_count=0;
        TreeNode *current=root;
        while(current!=NULL)
        {
            comparisons_count++;
            if(current->keyword == keyword)
            {
                cout<<" The meaning of "<<keyword<<" is : "<<current->meaning<<endl;
                cout<<" Number of comparisons needed to find "<<keyword<<" are : "<<comparisons_count<<endl;
                return ;
            }
            else if(keyword < current->keyword)
            {
                current=current->left;
            }
            else if(current->keyword < keyword)
            {
                current=current->right;
            }
        }

        cout<<" The Keyword : "<<keyword<<" doesn't exist in the Dictionary. "<<endl;
    }

    void update_word()
    {
        if(root==NULL)
        {
            cout<<" The Dictionary doesn't contains any keywords yet. "<<endl;
            return ;
        }

        string keyword;
        cout<<" Enter the keyword whose meaning you want to search in Dictionary : ";
        cin>>keyword;
        cin.ignore(100,'\n');
        TreeNode *current=root;
        while(current!=NULL)
        {
            if(current->keyword == keyword)
            {
                string new_meaning;
                cout<<" Update the meaning for the Keyword : "<<keyword<<" in the Dictionary : ";
                getline(cin,new_meaning);
                current->meaning=new_meaning;
                return ;
            }
            else if(keyword < current->keyword)
            {
                current=current->left;
            }
            else if(current->keyword< keyword)
            {
                current=current->right;
            }
        }

        cout<<" The Keyword : "<<keyword<<" doesn't exist in the Dictionary. "<<endl;
        char ch='n';
        cout<<" Do you want to add the keyword "<<keyword<<" in the Dictionary ? (y/n) "<<endl;
        cin>>ch;
        if(ch=='y')
        {
            insert_word();
        }
    }

    void ascending_order(TreeNode* temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        ascending_order(temp->left);
        cout<<temp->keyword<<" : "<<temp->meaning<<endl;
        ascending_order(temp->right);
    }
    void ascending_order()
    {
        if(root==NULL)
        {
            cout<<" The Dictionary doesn't contains any keywords yet. "<<endl;
            return ;
        }
        TreeNode *temp=root;
        cout<<" Displaying the Dictionary in ascending order : "<<endl;
        ascending_order(temp);
        return ;
    }

    void descending_order(TreeNode* temp)
    {
        if(temp==NULL)
        {
            return ;
        }

        descending_order(temp->right);
        cout<<temp->keyword<<" : "<<temp->meaning<<endl;
        descending_order(temp->left);
    }
    void descending_order()
    {
        if(root==NULL)
        {
            cout<<" The Dictionary doesn't contains any keywords yet. "<<endl;
            return ;
        }

        TreeNode *temp=root;
        cout<<" Displaying the Dictionary in descending order : "<<endl;
        descending_order(temp);
        return ;
    }

    // Helper function to find the maximum value node in the subtree rooted at `current`
    TreeNode* findMaximumKeyword(TreeNode* current)
    {
        while(current->right!=NULL)
        {
            current=current->right;
        }
        return current;
    }
    // Function to delete a node from a BST. Note that root is passed by
    // reference to the function    
    void delete_word(TreeNode* &current,string keyword)
    {
        // base case: the key is not found in the tree
        if(current==NULL)
        {
            cout<<" The Keyword : "<<keyword<<" is not present in the Dicionary. "<<endl;
            return ;
        }

        // if the given key is less than the root node, recur for the left subtree
        if(keyword < current->keyword)
        {
            delete_word(current->left,keyword);
        }
        // if the given key is more than the root node, recur for the right subtree
        else if(current->keyword < keyword)
        {
            delete_word(current->right,keyword);
        }
        // key found
        else
        {
            // Case 1: node to be deleted has no children (it is a leaf node)
            if(current->left==NULL && current->right)
            {
                // deallocate the memory and update root to null
                delete current;
                current=NULL;
            }
            // Case 2: node to be deleted has two children
            else if(current->left!=NULL && current->right!=NULL)
            {
                // find its inorder predecessor node
                TreeNode* predecessor=findMaximumKeyword(current->left);
                // copy value of the predecessor to the current node

                // recursively delete the predecessor. Note that the
                // predecessor will have at most one child (left child)
                current->keyword=predecessor->keyword;

                delete_word(current->left,predecessor->keyword);
            }
            // Case 3: node to be deleted has only one child
            else
            {
                // choose a child node
                TreeNode *child=(current->left!=NULL) ? current->left : current->right;
                TreeNode* curr=current;
                current=child;

                // deallocate the memory
                delete curr;
            }
        }
    }
    void delete_word()
    {
        if(root==NULL)
        {
            cout<<" The Dictionary doesn't contains any keywords yet. "<<endl;
            return ;
        }

        string keyword;
        cout<<" Enter the keyword whose meaning you want to delete in Dictionary : ";
        cin>>keyword;
        TreeNode* current=root;
        delete_word(current,keyword);
        cout<<" The Keyword : "<<keyword<<" deleted Successfully from the Dictionary. "<<endl;
        return ;

    }
};
int main()
{
    Dictionary obj;
    int option;
    do
    {
        cout<<endl;
        cout<<" ------------------------ Menu ------------------------ "<<endl;
        cout<<" 1. Insert the Keyword and it's Meaning in the Dictionary "<<endl;
        cout<<" 2. Search a Keyword in the Dictionary "<<endl;
        cout<<" 3. Update a Keyword's meaning in the Dictionary "<<endl;
        cout<<" 4. Display the Keyword's in Alphabetical Order (Ascending order) "<<endl;
        cout<<" 5. Dislpay the Keyword's in descending order "<<endl;
        cout<<" 6. Delete the keyword and it's Meaning from the Dictionary "<<endl;
        cout<<" 7. Exit "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        switch (option)
        {
        case 1:
            obj.insert_word();
            break;
        case 2:
            obj.search_word();
            break;
        case 3:
            obj.update_word();
            break;
        case 4:
            obj.ascending_order();
            break;
        case 5:
            obj.descending_order();
            break;   
        case 6:
            obj.delete_word();
            break;         
                    
        }
        cout<<endl;
    }while(option>=1 && option<=6);
    return 0;
}