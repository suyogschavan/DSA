//============================================================================
// Name        : prac1.cpp
// Author      : harshada
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct bst
	{
		int data;
		struct bst *left, *right;
	}node;
	node *root, *New, *temp, *parent, *lnode, *rnode;


class bintree
{

	public:
	node *que[20];
	int front, rear;

	bintree()
	{
		root = NULL;
		front = rear = -1;
	}

	void create();
	void display();
	void insert(node *, node *);
	void inorder(node *);
	void findmin();
	void minvalue(node *,int *);
	void find();
	void search(node **, int, node **);

	void order();
	int height(node *);

	void level(node *,int);
	void show();
	void swap();
	void swapping(node *);

	int minimum(node *);
	void fm();
};


int bintree::minimum(node *root)
{
 lnode = root;
 while(lnode->left!=NULL)
 {
	 lnode = lnode->left;
 }
 return (lnode->data);

}

//create tree
void bintree::create()
{
	New = new node;
	New->left = NULL;
	New->right = NULL;
	cout<<"\n enter the element::";
	cin>>New->data;
	if (root == NULL)
		root = New;
	else
		insert(root,New);

}

void bintree::insert(node *root, node *New)
{
	if (New->data < root->data)
	{
		if (root->left == NULL)
			root->left = New;
		else
			insert(root->left,New);
	}

	if (New->data > root->data)
		{
			if (root->right == NULL)
				root->right = New;
			else
				insert(root->right,New);
		}

	}

//display tree inorder
void bintree::display()
{
	if (root == NULL)
		cout << "Tree is not created";
	else
	{
		cout <<"\n The Tree is";
		inorder(root);
	}
}

void bintree::inorder(node *temp)
{
	if (temp != NULL)
	{
		inorder(temp->left);
		cout<<" "<<temp->data;
		inorder(temp->right);
	}

}

//find minimum value in tree
void bintree::findmin()
{
	int min = root->data;
	minvalue(root,&min);
	cout <<"\n Minimum value of node in the tree::"<<min;

}

void bintree::minvalue(node *temp, int *min)
{
	if(temp != NULL)
	{
		minvalue(temp -> left,min);
		if (temp->data < *min)
			*min = temp->data;
		//cout<<"\n"<<min<<"\t"<<temp->data<<"\n";
		//minvalue(temp->right,min);
	}
}

void bintree::find()
{
	int key;
	cout<<"\n Enter the element to find::";
	cin>> key;
	temp = root;
	search(&temp, key, &parent);
	if(temp == NULL)
		cout << "Element is not present";
	else
		cout << "\n Parent of node" << temp->data <<"is"<<parent->data;
}

//search particular node
void bintree::search(node **temp, int key, node **parent)
{
	if(*temp == NULL)
		cout<<"Tree is not created";
	else
	{
		while(*temp != NULL)
		{
			if((*temp)->data == key)
			{
				cout <<"\n Element"<<(*temp)->data<<"is present";
				break;
			}
			*parent = *temp;
			if((*temp)->data > key)
				*temp = (*temp)->left;
			else
				*temp = (*temp)->right;

		}
	}
	return;
}

//calculate height of tree
void bintree::order()
{
	int h = height(root);
		cout<<"height"<<h;
}

int bintree::height(node *root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lh = height(root->left);
		int rh = height(root->right);

		if (lh > rh)
			return(lh +1);
		else
			return(rh+1);
	}
}

//display tree levelwise
void bintree::show()
{
	int h = height(root);

		int i;
			for (i=1;i<=h;i++)
			{
				cout<<"\n";
				level(root,i);
			}
}


void bintree::level(node * root,int lev)
{
	if (root == NULL)
		return;
	if (lev == 1)
		cout<<""<<root->data<<"\t";
	else if (lev > 1)
	{
	    //New = root->left;
	    //temp = root->right;
		level(root->left,lev-1);
		level(root->right,lev-1);
	}
}

//swap the tree
void bintree::swap()
{
	cout<<"\n \t Original Tree";
	show();
	swapping(root);

	cout<<"\n \t Swap Tree";
	show();
	swapping(root);

}

void bintree::swapping(node *root)
{
	if (root!=NULL)
	{
		swapping(root->left);
		swapping(root->right);

		//swapping left child with right child

		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int main() {
	int choice;
	char ans = 'n';
	bintree tr;

	cout <<"\n \t Binary Search Tree";
	do
{
	cout << "\n 1. Create";
	cout << "\n 2. Display";
	cout << "\n 3. Longest Path Nodes";
	cout << "\n 4. Minimum Value";
	cout << "\n 5. Swap tree";
	cout << "\n 6. Search";
	cout << "\n\n enter Your Choice::";
	cin >> choice;

	switch(choice)
	{
	case 1:
		do{
		tr.create();
		cout << "\n Do you want to enter more element (y/n)";
		cin >> ans;
				}
			while(ans == 'y');
			break;
	case 2:
		cout <<"\n \t Display Binary Search Tree (INORDER)";
			tr.display();
			break;
	case 3:
			cout <<"\n \t Longest Path";
				tr.order();
				break;
	case 4:
			cout <<"\n \t Minimum value of Binary Search Tree::";
			//tr.findmin();
			cout<<tr.minimum(root);
				break;
	case 5:
				cout <<"\n \t SWAP of Binary Search Tree";
				tr.swap();
					break;
	case 6:
		cout <<"\n \t Search node in Binary Search Tree";
					tr.find();
						break;
	default :
	        cout << "Invalid choice";
	       // exit(0);

	}
}
while(choice != 7);


	return 0;
}
