#include<iostream> 
#include<stdlib.h> 
#include<string.h> 
#include<stdio.h> 

using namespace std; 

class node 
{ 
public: 
		char keyword[20]; 
		char meaning[20]; 
		node *left; 
		node *right; 
		int ht; 
		 node() 
		{ 
			 strcpy(meaning,""); 
			 strcpy(keyword,""); 
		} 
}; 

class tree 
{ 
	private: 
	node *root; 
	tree *t; 
	public: 
	tree() 
	{ 
		root=NULL; 

	} 
	void insert1(char key[20],char mean[20]) 
	{ 
		 
		root=insert(root,key,mean); 
	} 
	node *insert(node *T,char word[20],char mean[20]); 
	void preorder(node *); 
	void inorder(node *); 
	void postorder(node *); 
	void display(); 
	void modify(node *); 
	void delet(); 
	node * In_Succ(node *); 
	void ascending() 
	{ 
		inorder(root); 
	} 
	void descending(node *); 
	void search1(node *); 
	void search() 
	{ 
		search1(root); 
	} 
	void max_compare(node *); 
	node *Rotate_Left(node *T); 
	node *Rotate_Right(node *T); 
	int BF(node *T); 
	int height(node *T); 
}; 

int tree::BF(node*T) 
{ 
	int lh,rh; 
	if(T==NULL) 
	return 0; 
	else 
	{ 
		if(T->left==NULL) 
		{ 
			lh=0; 
		} 
		else 
		{ 
			lh=1+T->left->ht; 
		} 
		if(T->right==NULL) 
		{ 
			rh=0; 
		} 
		else 
		{ 
			rh=1+T->right->ht; 
		} 
	} 
	return(lh-rh); 
} 

node *tree::Rotate_Right(node*T) 
{ 
	node*temp; 
	temp=T->left; 
	T->left=temp->right; 
	temp->right=T; 
	T->ht=height(T); 
	temp->ht=height(temp); 
	return(temp); 
} 

node *tree::Rotate_Left(node*T) 
{ 
	node*temp; 
	temp=T->right; 
	T->right=temp->left; 
	temp->left=T; 
	T->ht=height(T); 
	temp->ht=height(temp); 
	return(temp); 
} 
int tree::height(node*T) 
{ 
	int left_height,right_height; 
	if(T==NULL) 
	{ 
		return(0); 
	} 
	if(T->left==NULL) 
	{ 
		left_height=0; 
	} 
	else 
	{ 
		left_height=1+(T->left->ht); 
	} 
	if(T->right==NULL) 
	{ 
		right_height=0; 
	} 
	else 
	{ 
		right_height=1+(T->right->ht); 
	} 
	if(left_height>right_height) 
		return(left_height); 
	else 
		return(right_height); 
} 


node *tree::insert(node *T,char word[20], char mean[20]) 
{ 
	if(T==NULL) 
	{ 
		T=new node(); 
	} 

	if(strcmp(T->keyword,"")==0) 
	{ 
		strcpy(T->keyword,word); 
		strcpy(T->meaning,mean); 
		T->left=NULL; 
		T->right=NULL; 
	} 
	else 
	{ 
		if(strcmp(word,T->keyword)>0) 
		{ 
			T->right=insert(T->right,word,mean); 

			if(BF(T)==-2) 
			{ 
				if(strcmp(word,T->right->keyword)>0) 
				{ 
					T=Rotate_Left(T); 
				} 
				else 
				{ 
					T->right=Rotate_Right(T->right); 
					T=Rotate_Left(T); 
				} 
			} 

		} 
		else 
		{ 
			if(strcmp(word,T->keyword)<0) 
			{ 
				T->left=insert(T->left,word,mean); 

				if(BF(T)==2) 
				{ 
					if((strcmp(word,T->left->keyword)<0)) 
					{ 
						T=Rotate_Right(T); 
					} 
					else 
					{ 
						T->left=Rotate_Left(T->left); 
						T=Rotate_Right(T); 
					} 
				} 
			} 
		} 
	} 
	T->ht=height(T); 

	return(T); 
} 

void tree::modify(node *head) 
{ 
	char data[20],mean[20],flag; 
	node *temp=head; 
	cout<<"\n Enter the word for which u want to modify the meaning"; 
	cin>>data; 
	cout<<"\n Enter the new meaning"; 
	cin>>mean; 
	while(temp!=NULL) 
	{ 
	      if(strcmp(temp->keyword,data)==0) 
	      { 
		strcpy(temp->meaning,mean); 
		flag=1; 
		break; 
	      } 

	      if(strcmp(temp->keyword,data)<0) 
		 temp=temp->right; 
	      else 
		 temp=temp->left; 
   } 

	 if(flag==1) 
	 { 
		cout<<"\n The keyword is____" <<temp->keyword<<"___ and its modified meaning is-"<<temp->meaning<<"\n"; 
	 } 
	 else 
	 { 
		cout<<"\n The word" <<data<<"isnot present in the BST \n"; 
	 } 
	 display(); 

} 

void tree::delet() 
{ 
   node *temp,*parent,*x,*in_succ; 
   temp=root;      //'head' is pointer to root node 
   char data[20]; 
   int flag; 
   cout<<"\n Enter the word u want to delete"; 
   cin>>data; 
   parent=temp; 
   while(temp!=NULL) 
   { 
      if(strcmp(temp->keyword,data)==0) 
      { 
	flag=1; 
	break; 
      } 

      if(strcmp(temp->keyword,data)<0) 
      { 
	parent=temp; 
	temp=temp->right; 
      } 
      else 
	 { 
		parent=temp; 
		temp=temp->left; 
	 } 
   } 
	 if(flag!=1) 
	 { 
		cout<<"\n The word--" <<data<<"--isnot present in the BST to delete\n"; 
	 } 
	 else 
	 { 
		if(temp->left==NULL && temp->right==NULL) 
		{ 
			if(parent->left==temp) 
			{ 
				parent->left=NULL; 
				delete temp; 
			} 
			else if(parent->right==temp) 
			{ 
				parent->right=NULL; 
				delete temp; 
			} 
		} 
		else if(temp->left!=NULL && temp->right==NULL) 
		{ 
			if(parent->left==temp) 
			{ 
				parent->left=temp->left; 
				delete temp; 
			} 
			else if(parent->right==temp) 
			{ 
				parent->right=temp->left; 
				delete temp; 
			} 
		} 
		else if(temp->right!=NULL && temp->left==NULL) 
		{ 
			if(parent->left==NULL) 
			{ 
				parent->left=temp->right; 
			} 
			else if(parent->right==temp) 
			{ 
				parent->right=temp->right; 
			} 
		} 
		else if(temp->left!=NULL && temp->right!=NULL) 
		{ 
			parent=temp; 
			x=temp->right; 
			in_succ=In_Succ(parent); 
			strcpy(parent->keyword,in_succ->keyword); 
			strcpy(parent->meaning,in_succ->meaning); 
			if(x->left!=NULL) 
			{ 
				if(x->left->left==NULL) 
				{ 
					x->left=x->left->right; 
				} 
				else 
				{ 
					x->left->left=x->left->left->right; 
				} 
			} 
			else 
			{ 
				parent->right=x->right; 
			} 
		} 
	 cout<<"\n The node has been deleted.\n"; 
	  } 
} 

node *tree::In_Succ(node *root) 
{ 
	node *trav; 
	trav=root; 
	trav=trav->right; 
	while(trav->left!=NULL) 
	{ 
		trav=trav->left; 
	} 
	return trav; 
} 

void tree::preorder(node *root) 
{ 
	if(root!=NULL) 
	{ 
		cout<<endl<<(root)->keyword<<"   !   "<<(root)->meaning; 
			preorder((root)->left); 
			preorder((root)->right); 

	} 
} 


void tree::inorder(node *root) 
{ 
	if(root!=NULL) 
	{ 
		inorder((root)->left); 
		cout<<endl<<(root)->keyword<<"   !   "<<(root)->meaning; 
		inorder((root)->right); 

	} 
} 

void tree::descending(node *root) 
{ 
	if(root!=NULL) 
	{ 
		descending((root)->right); 
		cout<<endl<<(root)->keyword<<"   !   "<<(root)->meaning; 
		descending((root)->left); 

	} 
} 


void tree::postorder(node *root) 
{ 
	if(root!=NULL) 
	{ 
		postorder((root)->left); 
		postorder((root)->right); 
		cout<<endl<<(root)->keyword<<"   !   "<<(root)->meaning; 
	} 
} 


void tree::display() 
{ 
	int ch; 
	do{ 
	cout<<endl<<"Enter ur choice"<<endl; 
	cout<<"1.Pre-order"<<endl; 
	cout<<"2.In-order"<<endl; 
	cout<<"3.Post-order"<<endl; 
	cout<<"4.Modify	"<<endl; 
	cout<<"5.Search"<<endl; 
	cout<<"6.Delete \n"; 
	cout<<"7.Ascending order \n"; 
	cout<<"8.Descending order \n"; 
	cout<<"9.Max Comparisons\n"; 
	cout<<"0.Exit"<<endl; 
	cin>>ch; 
	switch(ch) 
	{ 
		case 1:cout<<"\n KEYWORD"<<"   !   "<<"MEANING"; 
		       cout<<"\n_______________________________"; 
		       preorder(root); 
		       break; 
		case 2:cout<<"\n KEYWORD"<<"   !   "<<"MEANING"; 
		       cout<<"\n_______________________________"; 
		       inorder(root); 
		       break; 
		case 3:cout<<"\n KEYWORD"<<"   !   "<<"MEANING"; 
		       cout<<"\n_______________________________"; 
		       postorder(root); 
		       break; 
		case 4:modify(root); 
		       break; 
		case 5:search(); 
		       break; 
		case 6:delet(); 
		       cout<<"\n Preorder traversal is:\n"; 
		       cout<<"\n KEYWORD"<<"   !   "<<"MEANING"; 
		       cout<<"\n_______________________________"; 
		       preorder(root); 
		       break; 
		case 7:ascending(); 
		       break; 
		case 8:descending(root); 
		       break; 
		case 9:max_compare(root); 
		       break; 
		case 0:exit(0); 
		default:cout<<"\n Wrong choice"; 
	} 
	} while(ch!=0); 
} 

void tree::search1(node *head)       //the function belongs to class 'tree' 
{ 
   node *temp=head;      //'head' is pointer to root node 
   char data[20]; 
   int flag; 
   cout<<"\n Enter the word u want to search"; 
   cin>>data; 
   while(temp!=NULL) 
   { 
      if(strcmp(temp->keyword,data)==0) 
      { 
	flag=1; 
	break; 
      } 

      if(strcmp(temp->keyword,data)<0) 
	 temp=temp->right; 
      else 
	 temp=temp->left; 
   } 

	 if(flag==1) 
	 { 
		cout<<"\n The word---" <<data<<"---is present in the BST \n"; 
	 } 
	 else 
	 { 
		cout<<"\n The word" <<data<<"isnot present in the BST \n"; 
	 } 
	 display(); 
} 

void tree::max_compare(node *head)       //the function belongs to class 'tree' 
{ 
   node *temp=head;      //'head' is pointer to root node 
   char data[20]; 
   int flag,count=0; 
   cout<<"\n Enter the word u want to search"; 
   cin>>data; 
   while(temp!=NULL) 
   { 
      if(strcmp(temp->keyword,data)==0) 
      { 
	count++; 
	flag=1; 
	break; 
      } 

      if(strcmp(temp->keyword,data)<0) 
	 temp=temp->right; 
      else 
	 temp=temp->left; 
   } 

	 if(flag==1) 
	 { 
		cout<<"\n The max comparisons for the word:  "<<count<<" \n"; 
	 } 
	 else 
	 { 
		cout<<"\n The word " <<data<<" isnot present in the BST \n"; 
	 } 
	 display(); 
} 


int main() 
{ 
	tree b; 
	char key[20],mean[20]; 
	FILE *fp; 
	fp=fopen("input.dat","r"); 
	if(fp==NULL) 
	{ 
		cout<<"\n File opening error."; 
		exit(0); 
	} 
	cout<<"\n Reading keywords and meaning from the dictionary"; 
	while(!feof(fp)) 
	{ 
		fscanf(fp,"%s%s",key,mean); 
		b.insert1(key,mean); 
		fflush(fp); 
	} 
	b.display(); 
	fclose(fp); 
	return 0; 
}
