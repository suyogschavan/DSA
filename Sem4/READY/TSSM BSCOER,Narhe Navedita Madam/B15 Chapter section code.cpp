#include<iostream>
using namespace std;

struct book_node
{
	char title[15];
	int chapt_count;
	struct book_node *down[10];
	
}*root;  

class book
{
	public:
		void create_tree();
		void display(book_node *r);
		
	book()
	{
	    	root=NULL;
	}
};

void book::create_tree()
{
	 int i,j,k;
	root=new book_node;
	cout<<"Enter name of the book: "<<endl;
	cin>>root->title;
	cout<<"Enter total number of chapters in the book: "<<endl;
	cin>>root->chapt_count;
//	cout<<root->chapt_count;
	for(i=0;i<root->chapt_count;i++)
	{	
	root->down[i]=new book_node;
	cout<<"Enter Name for chapter "<<i+1<<endl; 
	cin>>root->down[i]->title;
	cout<<"Enter no. of sections in  "<<root->down[i]->title<<endl;
	cin>>root->down[i]->chapt_count;
	cout<<"Enter details for chapter " <<i+1<<endl;
	for(j=0;j<root->down[i]->chapt_count;j++)
	{
		 
	root->down[i]->down[j]=new book_node;
	cout<<"Enter title for section "<<j+1<<endl;
	c  in>>root->down[i]->down[j]->title;
	cout<<"Enter no. of sub sections in section "<<j+1<<endl;
	cin>>root->down[i]->down[j]->chapt_count;
	for(k=0;k<root->down[i]->down[j]->chapt_count;k++)
	{
	root->down[i]->down[j]->down[k]=new book_node;
	cout<<"Enter title for subsection "<<k+1<<endl;
	cin>>root->down[i]->down[j]->down[k]->title;
	}
	}
	
} 
	 
	
	
} 

void book::display(book_node *r)
{    int i,j,k;
	if(r!=NULL)
	{
		cout<<"****index****"<<endl; 
		cout<<"Book Title: "<<r->title<<endl<<endl;
		for(i=0;i<r->chapt_count;i++)
    	{	
	       cout<<"Chapter " <<i+1<<": "<<r->down[i]->title<<endl;
	       for(j=0;j<r->down[i]->chapt_count;j++)
		    {
		   
	       cout<<"Section "<<j+1<<endl;
		   for(k=0;k<r->down[i]->down[j]->chapt_count;k++)
		   {
			 cout<<"Sub Section "<<k +1<<endl;
		   cout<<r->down[i]->down[j]->down[k]->title<<endl; 
        	} 
          }
		}
		
		
	}
}

int main()
{
	int choice;
	book book;
	while(1)
	{
		cout<<"Menu:"<<endl;
		cout<< "Book tree structure"<<endl;
		cout<<"Create tree"<<endl;
		cout<< "Display tree"<<endl;
		cout<<"Exit"<<endl;
		cout<< "Enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			book.create_tree();
			break;
			
		case 2:
			book.display(root);
			break;
		case 3:
			exit(0);
			
		}
	}
	return 0;
}
