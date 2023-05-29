#include<iostream>
#include<malloc.h>
#include<string>
using namespace std;

struct node {
    string name;
    int ch_count;
    struct node *child[10]; 
};

struct node *Root;

class DB{
    public:

    DB(){
        Root = NULL;
    }

    void createTree();
    void displayTree(struct node *);
};


void DB::createTree(){
    // int tchapters;
    Root = new node;
    cout<<"Enter the name of book";
    cin>>Root->name;
    cout<<"Enter the number of chapters in book ";
    cin>>Root->ch_count;
    for (int i = 0; i < Root->ch_count; i++)
    {
        Root->child[i] = new node;
        cout<<"Enter the name of Chapter ";
        cin>>Root->child[i]->name;
        cout<<"Enter the number of Sections: ";
        cin>>Root->child[i]->ch_count;
        for (int j = 0; j < Root->child[i]->ch_count; j++)
        {
            Root->child[i]->child[j] = new node;
            cout<<"Enter the name of Section ";
            cin>>Root->child[i]->child[j]->name;
            cout<<"Enter the number of SubSections ";
            cin>>Root->child[i]->child[j]->ch_count;
            for (int k = 0; k < Root->child[i]->child[j]->ch_count; k++)
            {
                Root->child[i]->child[j]->child[k] = new node;
                cout<<"Enter the name of subsection ";
                cin>>Root->child[i]->child[j]->child[k]->name;
            }
            
        }
        
    }
    
}

void DB::displayTree(struct node *temp){
    temp = Root;
    cout<<"Book Title : "<<temp->name;
    cout<<"\nNumber of chapters: "<<temp->ch_count;
    for (int i = 0; i < temp->ch_count; i++)
    {
        cout<<"\nChapter no. "<<i+1<<" name: "<<temp->child[i]->name;
        cout<<"\nNo. of sections in this chapter: "<<temp->child[i]->ch_count;
        for (int j = 0; j < temp->child[i]->ch_count; j++)
        {
            cout<<"\nName of section"<<j+1<<" : "<<temp->child[i]->child[j]->name;
            cout<<"\nNumber of subsections in this section: "<<temp->child[i]->child[j]->ch_count;
            for (int k = 0; k <temp->child[i]->child[j]->ch_count; k++)
            {
                cout<<"\nName of subsection"<<k<<temp->child[i]->child[j]->child[k]->name;
            }
            
        }
        
    }
    

}
 
int main(){
    DB db;
    db.createTree();
    db.displayTree(Root);
}

