#include<iostream>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int get_height(struct Node *n){
    if(n==NULL){
        return 0;
    }else{
        return n->height;
    }
}

struct Node *createNode(int key){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = node -> right = NULL;
    node->key = key;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node *n){
    if(n==NULL){
        return 0;
    }
    return get_height(n->left)-get_height(n->right);
}

struct Node* leftRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;
}