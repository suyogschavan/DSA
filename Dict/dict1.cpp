#include <iostream>
using namespace std;

class keynode
{
public:
    string keyword;
    string meaning;
    keynode *left;
    keynode *right;

    keynode()
    {
        keyword = "";
        meaning = "";
        left = right = NULL;
    }

    keynode(string k, string m)
    {
        keyword = k;
        meaning = m;
        left = right = NULL;
    }
};

class Dictionary
{
public:
    keynode *root;

    Dictionary()
    {
        root = NULL;
    }

    void insert_new()
    {
        string key, mean;
        cout << "Enter the keyword you wan't to insert: "<<endl;
        cin>>key;
        cout << "Enter the meaning of your keyword: "<<endl;
        cin>>mean;

        keynode *temp = new keynode(key, mean);
        if (root == NULL)
            root = temp;
        else
        {
            keynode *d_root = root;
            while (1)
            {
                if (d_root->keyword > temp->keyword)
                {
                    if (d_root->left == NULL)
                    {
                        d_root->left = temp;
                        return;
                    }
                    else
                    {
                        d_root = d_root->left;
                    }
                }
                else
                {
                    if (d_root->right == NULL)
                    {
                        d_root->right = temp;
                        return;
                    }
                    else
                    {
                        d_root = d_root->right;
                    }
                }
            }
            cout << "keyword inserted successfully!" << endl;
        }
    }

    void update()
    {
        string key, mean;
        cout << "Enter the keyword you wan't to update: ";
        cin >> key;
        keynode *temp = root;
        int comp_counter=0;
        while (1)
        {
            comp_counter++;
            if (temp->keyword == key)
            {
                cout << "Write the new meaning of this keyword: " << endl;
                cin>>mean;
                temp->meaning = mean;
                cout << "Meaning updated successfully" << endl;
                cout << "No. of comparisons made: " << comp_counter << endl;
                return;
            }
            else
            {
                if (temp->keyword > key)
                {
                    temp = temp->left;
                }
                else
                {
                    if (temp->keyword < key)
                        temp = temp->right;
                }
            }
        }
            cout << "Keyword dosen't exists in dictionary." << endl;
    }

    void ascending(keynode *r){
        if (r==NULL)
        {
            return;
        }
        ascending(r->left);
        cout<<r->keyword<<" : "<<r->meaning<<endl;
        ascending(r->right);
        
    }

    void ascending_helper(){
        if(root == NULL){
            cout<<"Dictionary is Empty."<<endl;
            return;
        }
        keynode *temp = root;
        ascending(temp);
        cout<<"Dictionary printed successfuly"<<endl;
        return;
    }
};

int main() {
    int ch;
    Dictionary d;
    cout<<"What you wan't to do in Dictionary? "<<endl;
    do
    {
        cout<<"Enter 1 to insert new keyword and meaning"<<endl;
        cout<<"Enter 2 to update existing keyword's meaning"<<endl;
        cout<<"Enter 3 to display the data in ascending order"<<endl;
        cin>>ch;

        switch (ch)
        {
        case 1:
            d.insert_new();
            break;
        
        case 2:
            d.update();
            break;
        case 3:
            d.ascending_helper();
            break;
        default:
            break;
        }
    
    } while (ch!=0);
    
    
}