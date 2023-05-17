#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
};

class tree
{
	public:
		node *root,*temp;
		int height1(node *T);
		int print0(node *T);
		node * mirror1(node *T);
		tree() 
		{
		 root=NULL;
		}
		void create();
		void insert(node *,node *);
		int height()
		{
		return(height1(root));
		}
		
		void level_wise();
		void preorder(node *);
		void min(node *);

		void search(node *,int);
};

class Q
{
		node *data[30];
		int R,F;
		public:
			Q(){ R=F=-1; }
			void init()
			{
				R=F=-1;
			}
int empty()
{
		if(R==-1)
			return 1;
		return 0;
}

void insert(node *p)
{
		if(empty())
				R=F=0;
		else
				R=R+1;
		data[R]=p;
}

node *Delete()
{
		node *p=data[F];
		if(R==F)
			R=F=-1;
		else
			F=F+1;
		return(p);
}
};

int tree::height1(node *T)
{
		if(T==NULL)
		return(0);
		
		if(T->left==NULL && T->right==NULL)
		return(0);
		
	return(max(height1(T->left),height1(T->right))+1);
}


int tree::print0(node *T)
{
		if(T==NULL)
			return(0);
		if(T->left==NULL && T->right==NULL)
		{
			cout<<" "<<T->data;
			return(1);
		}
		return(print0(T->left)+print0(T->right));
}

void tree::create()
{
root=NULL;
	char ch;
	do{
	temp=new node;
	cout<<" enter data"<<endl;
	cin>>temp->data;
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		insert(root,temp);
	}
	cout<<"do u want to continue"<<endl;
	cin>>ch;
	}
	while(ch=='y');
}

void tree::insert(node *root,node *temp)
{char ch1;

	if(temp->data<root->data)
	{if(root->left==NULL)
	root->left=temp;
	else
	insert(root->left,temp);
	}
	else if(temp->data>root->data)
	{if(root->right==NULL)
		root->right=temp;
		else
		insert(root->right,temp);
	}
}
node * tree::mirror1(node *T)
{
	node *temp;
	if(T==NULL)
		return NULL;
	else
	{
		temp=T->left;
		T->left=mirror1(T->right);
		T->right=mirror1(temp);
		return T;
	}
}

void tree::level_wise()
{
	Q q1,q2;
	node *p1,*p2;
	node *T=root;
	if(T==NULL)
		return;
	q1.insert(T);
	cout<<"\n "<<T->data;
	while(!q1.empty())
	{
		cout<<"\n";
		q2.init();
		while(!q1.empty())
		{
			p1=q1.Delete();
			if(p1->left !=NULL)
			{
			q2.insert(p1->left);
			cout<<" "<<p1->left->data;
			}

			if(p1->right !=NULL)
			{
			q2.insert(p1->right);
			cout<<" "<<p1->right->data;
			}
        }   

        	q1=q2;
   }
}

void tree::preorder(node *root)
{
	if(root!=NULL)
   {
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
   }
}

void tree::min(node *root)
{
	while(root->left!=NULL)
	root=root->left;
	cout<<root->data;
}

void tree::search(node * root,int x)
{
	int flag=0;
	while(root!=NULL)
	{
		if(x<root->data)
		{
			root=root->left;
		}
		else if(x>root->data)
		{
			root=root->right;
		}
		else if(x==root->data)
		{
			flag=1;
			break;
		}
	}
if(flag==1)
	cout<<"data found";
else 
	cout<<"not found";
}

int main()
{
	tree t1;
	int xx,op,x,c;
	do
{
	cout<<"\n\n1)Create\n2)Mirror";
	cout<<"\n3)No of nodes in longest Path\n4)preorder display\n 5.minimum value\n6.Search";
	cout <<"\nEnter Your Choice :"<<endl;
	cin>>op;
	switch(op)
	{
	case 1: 
			t1.create();
			break;
	case 2:
			cout<<"\n level Wise traversal on original tree \n";
			t1.level_wise();
			t1.root=t1.mirror1(t1.root);
			cout<<"\n level Wise traversal on mirror tree \n";
			t1.level_wise();
			break;
	case 3: 
			cout<<"\nHeight = "<<t1.height();
			break;
	case 4:
			t1.preorder(t1.root);
			break;
	case 5: 
			t1.min(t1.root);
			break;
	case 6:
			cout<<"enter element to search";
			cin>>x;
			t1.search(t1.root,x);
			break;
	case 7:
			exit(0);
	}
}
while(op!=7);
return 0;
}
