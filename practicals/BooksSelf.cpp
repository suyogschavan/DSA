/* ================================================== 
 Description     : Experiment no. iDK
 Author          : Suyog Chavan
 Reach me here   : https://suyogchavan.me 
 Date of creation: Tuesday, 16 May 2023 
 credit       : ©suyogschavan03@gmail.com
================================================== */

#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
    string label;
    int child_count;
    struct Node *child[10];
};

struct Node *Root;

class Tree{
    public:
    void create();
    void display(struct Node *root);

};

void Tree::create(){
    // struct Node *b1;
    Root = new Node;
    cout<<"Enter the name of Book : ";
    cin>>Root->label;
    // cin.get();
    // getline(cin, Root->label);
    cout<<"Enter the number of chapters in book : "<<Root->label<<" : ";
    cin>>Root->child_count;
    for(int i = 0; i<Root->child_count; i++){
        Root->child[i] = new Node;
        cout<<"Enter the name of chapter"<<i+1<<" : ";
        cin>>Root->child[i]->label;
        cout<<"Enter the number of sections in the chapter"<<i+1<<" : ";
        cin>>Root->child[i]->child_count;
        for (int j = 0; j < Root->child[i]->child_count; j++)
        {
            Root->child[i]->child[j]= new Node;
            cout<<"Enter the name of section "<<j+1<<" : ";
            cin>>Root->child[i]->child[j]->label;
            cout<<"Enter the number of SubSections in "<<Root->child[i]->child[j]->label<<" : ";
            cin>>Root->child[i]->child[j]->child_count;
            for (int k = 0; k < Root->child[i]->child[j]->child_count; k++)
            {
                Root->child[i]->child[j]->child[k]= new Node;
                cout<<"Enter the name of SubSection "<<k+1<<" : ";
                cin>>Root->child[i]->child[j]->child[k]->label;
            }
            
        }
        
    }
    
};

void Tree::display(struct Node* root ){
    if (root==NULL)
    {
        cout<<"Book Heirarchy is Empty"<<endl;
    }else{
        cout<<"----------------------------------------"<<endl;
        cout<<"Name of Book : "<<root->label<<endl;
        cout<<"Number of Chapters in Book : "<<root->child_count<<endl;
        for (int i = 0; i < root->child_count; i++)
        {
            cout<<"Name of chapter "<<i+1<<" : "<<root->child[i]->label<<endl;
            cout<<"Number of sections in chapter "<<root->child[i]->label<<" : "<<root->child[i]->child_count<<endl;
            if (root->child[i]->child_count != 0)
            {
                for (int j = 0; j < root->child[i]->child_count; j++)
                {
                    cout<<"Name of section "<<j+1<< ": "<<root->child[i]->child[j]->label<<endl;
                    cout<<"Number of subsection in "<<root->child[i]->child[j]->label<<" : "<<root->child[i]->child[j]->child_count<<endl;
                    if(root->child[i]->child[j]->child_count!=0){
                    for (int k = 0; k < root->child[i]->child[j]->child_count; k++)
                    {
                        cout<<"Name of Subsection "<<k+1<<" : " <<root->child[i]->child[j]->child[k]->label<<endl;
                    }
                    }
            }
            }
            
            
        }
        cout<<"----------------------------------------"
        


    }
    
};

int main(){
    Tree t;
    t.create();
    t.display(Root);
}
