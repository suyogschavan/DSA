#include <iostream>
using namespace std;

class node
{
public:
    string keyword;
    string meaning;
    node *left;
    node *right;
    node(string k, string m)
    {
        keyword = k;
        meaning = m;
        left = right = NULL;
    }
};

class Dict
{
    node *root = NULL;

public:
    // to insert new keywords
    void insert_new()
    {
        string key, mean;
        cout << "Enter the keyword: ";
        cin >> key;
        cout << "Enter the meaning of this keyword: ";
        cin >> mean;

        node *newnode = new node(key, mean);

        if (root == NULL)
        {
            root = newnode;
            return;
        }

        node *r;
        r = root;
        while (1)
        {
            if (r->keyword > newnode->keyword)
            {
                if (r->left == NULL)
                {
                    r->left = newnode;
                    return;
                }
                else
                    r = r->left;
            }
            else if (r->keyword < newnode->keyword)
            {
                if (r->right == NULL)
                {
                    r->right = newnode;
                    return;
                }
                else
                    r = r->right;
            }
        }
        cout << "!!!Keyword Inserted Successfully!!!" << endl;
    }
    void update()
    {
        string key;
        cout << "Enter the keyword you wan't to update: ";
        cin >> key;
        if (root == NULL)
        {
            cout << "Dictionary is Empty!" << endl;
            return;
        }
        node *temp = root;
        while (1)
        {
            if (temp->keyword == key)
            {
                string mean;
                cout << "Keyword Found" << endl;
                cout << "Enter the NEW meaning for this keyword: ";
                cin >> mean;
                temp->meaning = mean;
                cout << "Keyword Changed Successfully!!!" << endl;
                return;
            }
            else if (temp->keyword > key)
            {
                temp = temp->left;
            }
            else if (temp->keyword < key)
            {
                temp = temp->right;
            }

            cout << "Keyword Not found" << endl;
            break;
        }
    }
    void search()
    {
        string key, mean;
        cout << "Enter the keyword you wan't to search: ";
        cin >> key;
        if (root == NULL)
        {
            cout << "Dictionary is Empty!!!" << endl;
            return;
        }
        int counter = 0;
        node *temp = root;
        while (1)
        {
            counter++;
            if (temp->keyword == key)
            {
                cout << key << " Found after " << counter << " comparisons." << endl;
                cout<<key<<" meaning: "<<temp->meaning<<endl;
                return;
            }
            else if (temp->keyword > key)
                temp = temp->left;
            else if (temp->keyword < key)
                temp = temp->right;
            else
            cout<<"Keyword Not found in Dictionary!!!"<<endl;
        }
    }
    void display(){
        cout<<"Printing the data of Dictionary in Ascending Order:"<<endl;
        node *temp = root;
        ascending(temp);
    }
    void ascending(node *temp){
        if(temp == NULL)
            return;
        ascending(temp->left);
        cout<<temp->keyword<<" : "<<temp->meaning<<endl;
        ascending(temp->right);
    }
};

int main() {
    Dict d;
    cout<<"What you wan't to do?"<<endl;
    int ch;
    do
    {
        cout<<"-------------------------MENU-------------------------"<<endl;
        cout<<"1: Insert new keyword."<<endl;
        cout<<"2: Update the keyword."<<endl;
        cout<<"3: Search the keyword."<<endl;
        cout<<"4: Print the dictionary."<<endl;
        cout<<"0: EXIT."<<endl;
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
            d.search();
            break;
        case 4:
            d.display();
            break;

        default:
            break;
        }

    } while (ch!=0);
    
}