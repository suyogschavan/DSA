#include<iostream>
#include<malloc.h>
#define t struct treeNode 
#define allocate (struct treeNode*)malloc(sizeof(struct treeNode))
using namespace std;

struct treeNode{
    int data;
    struct treeNode *lchild, *rchild;
};
struct treeNode *Root;

class tree{
    public:
    int getData();
    void create();
    void insert_node(t *, int);
    void display();
    void inorder(t *);
    void preorder(t *);
    void postorder(t *);
    void descendingorder(t *);
    int getMax();
    int getMin();
    
};

tree::getData(){
    int d;
    cout<<"Enter the data: ";
    cin>>d;
    return d;
}

void tree::create(){
    int n;
    cout<<"Enter the no. nodes you wan't to insert: "<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
    t *newNode;
    newNode = allocate;
    newNode->data = getData();
    newNode->rchild = NULL;
    newNode->lchild = NULL;
    if(Root == NULL){
        Root = newNode;
    }else{
        insert_node(Root, newNode->data);
    }
    }

}

void tree::insert_node(t *root, int d){
    t *newnode = allocate;
    newnode->data = d;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if (root==NULL)
    {
        cout<<"Please create the tree first"<<endl;
    }else{
        if(root->data>d){
            if(root->lchild==NULL){
                root->lchild= newnode;
            }else{
                insert_node(root->lchild, d);
            }
        }else{
            if(root->rchild == NULL){
                root->rchild=newnode;
            }else{
                insert_node(root->rchild, d);
            }
        }
    }
    
}


// for display
void tree:: display(){
    t *temp;
    temp = Root;
    //null condition
    int ch;
    cout<<"Enter your choice: \n1. Inorder (ascending)\n2. Preorder\n3. Postorder\n4. Descending"<<endl;
    cin>>ch;
    switch (ch)
    {
    case 1:
        cout<<"INORDER: ";
        inorder(temp);
        break;
    case 2:
        preorder(temp);
        break;
    case 3:
        postorder(temp);
        break;
    case 4:
        descendingorder(temp);
        break;
    
    default:
        break;
    }
    // inorder(temp);
}

void tree::inorder(t *root){

    if(root==NULL){
        return;
    }else{
        inorder(root->lchild);
        cout<<root->data<<" ";
        inorder(root->rchild);
    }
}

// giving segmentation fault idk why>>,
void tree::preorder(t *root){
    if(root = NULL){
        return;
    }
        cout<<root->data<<" "<<endl;
        preorder(root->lchild);
        preorder(root->rchild);
    
}

void tree::postorder(t *root){
    if(root == NULL){
        return;
    }else{
        postorder(root->lchild);
        postorder(root->rchild);
        cout<<root->data<<" ";
    }
}

void tree::descendingorder(t *root){
    if(root==NULL)
    return;
    descendingorder(root->rchild);
    cout<<root->data<<" ";
    descendingorder(root->lchild);
}

int tree::getMin(){
    t *temp;
    temp = Root;
    while(temp->lchild!=NULL)
    temp=temp->lchild;
    return temp->data;
}

int tree::getMax(){
    t *temp;
    temp = Root;
    while(temp->rchild!=NULL)
    temp = temp->rchild;
    return temp->data;
}

int main(){
    tree obj;
    obj.create();
    obj.display();
    // int dada = obj.getMax();
    // cout<<"MINIMUM="<<dada<<endl;
}
