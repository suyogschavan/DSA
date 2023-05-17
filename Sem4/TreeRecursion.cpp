#include<iostream>
#include<malloc.h>
using namespace std;

struct treeNode{
    int data;
    struct treeNode *lChild, *rChild;
};
struct treeNode *head = NULL;
void create(){
    struct treeNode *newNode;
    newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    if(head==NULL){
        head = newNode;
    }
}
