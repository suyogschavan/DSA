

/*PROBLEM STATEMENT:-
 * There are flight paths between cities. If there is a flight between city A and city B then there is
an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. The node can be represented by airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph. 
 */
#include <iostream>
#include<string.h>
#include<iomanip>

using namespace std;

class grp
{
	char city[10][25];
	char scity[25];
	char dcity[25];
	int a[10][10],i,j,n;
	int w;
public:
	void init();
	void create();
	void display();
};

void grp::init()
{

	cout<<"\n Enter the no of cities"<<endl;
	cin>>n;
	cout<<"\nEnter the name of cities "<<endl;
	for(i=0;i<n;i++)
		cin>>(city[i]);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
}

void grp::create()
{
	int k=0,m;

	cout<<"Enter the source city"<<endl;
	cin>>scity;
	cout<<"Enter the destination city"<<endl;
	cin>>dcity;
	cout<<"Enter time to reach the destination city"<<endl;
	cin>>w;


	for(m=0;m<n;m++)
	{

		if(! strcmp(scity,(city[m])))
			i=m;
	}

	for(m=0;m<n;m++)
	{

		if(! strcmp(dcity,(city[m])))
			j=m;
	}

	a[i][j]=w;
}

void grp::display()
{
	cout<<"\nThe adjacency matrix is"<<endl;

	for(i=0;i<n;i++)
	{
		cout<<endl;
		for(j=0;j<n;j++)


			cout<<setw(5)<<a[i][j]<<" ";
	}

}


int main()
{
	grp g;
	int p,z;
	g.init();
	cout<<"\nHow many edges do u want to enter?"<<endl;
	cin>>p;
	for(z=0;z<p;z++)
		g.create();
	cout<<endl;
	g.display();


	return 0;
}

/*OUTPUT:-
 *  Enter the no of cities
4

Enter the name of cities
mumbai
pune
goa
jaipur

How many edges do u want to enter?
4
Enter the source city
mumbai
Enter the destination city
pune
Enter time to reach the destination city
32
Enter the source city
pune
Enter the destination city
goa
Enter time to reach the destination city
56
Enter the source city
goa
Enter the destination city
jaipur
Enter time to reach the destination city
120
Enter the source city
jaipur
Enter the destination city
mumbai
Enter time to reach the destination city
140


The adjacency matrix is

    0    32     0     0
    0     0    56     0
    0     0     0   120
  140     0     0     0
 */
