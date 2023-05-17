

#include <iostream>
using namespace std;

class prim		//class defination for the prims program
{
	int visited[10] ,weight[10][10] ,final[10][10] ,min;	
	int total_cost,num,i,j,k,l;
public:
	prim()		//contructor
	{
		total_cost=0;
		min=0;
	}
	void read();
	void calmin();
	void disp();
};

void prim::read() 	//to accept the weighted adjacency matrix
{
	cout<<"\n Number of offices you want you want to connect: ";
	cin>>num;
	for(i=0;i<num;i++)	//initializing visited array with 0
		{
			visited[i]=0;
		}
	for(i=0;i<num;i++)	//initializing the final output array with 0
	{
		for(j=0;j<num;j++)
		{
			final[i][j]=0;
		}
	}
	cout<<"\n Enter the cost of travelling between two houses:\n";
	//Entering the cost of phone charges between two cities
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			cin>>weight[i][j];
		}
	}
}

void prim::disp()	//display of the required minimum path
{
	cout<<"\n To have the minimum cost the traveled path should be:\n";
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			cout<<final[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"\nThe total cost of traveling is: ";
	cout<<total_cost;
}

void prim::calmin()
{
	min=9999;
	total_cost=0;
	//Find the path having minimum cost from the entire group
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			if(weight[i][j]<min && weight[i][j]!=0)
		//Find the minimum number and save its position in the matrix
			{
				min=weight[i][j];
				//save the value of minimum path
				k=i;// save the row
				l=j;//save the column
			}
		}
	}

	cout<<"\nEdge:"<<k<<"-"<<"having distance:"<<min;
	visited[k]=1;//assigning 1 for the visited house
	visited[l]=1;
	final[k][l]=weight[k][l];//assigning the value to the final matrix
	final[l][k]=weight[l][k];
	total_cost=min;

	for(int m=0;m<num-2;m++)
	{
		min=9999;
		//the loop will find the minimum path between cities
		for(i=0;i<num;i++)
                //For the current vertex find min value 
                //from visited and non-zero vertices
		{
			if(visited[i]==1)
			//If the city is already visited
			{
				for(j=0;j<num;j++)
				{
				  if(visited[j]!=1)
				  {
					 if(weight[i][j]<min && weight[i][j]!=0)
					  //Find the minimum number 
					  //and save its position
					 {
					        min=weight[i][j];
						k=i;
						l=j;
					 }
				  }
				}
			}
		}
		cout<<"\nEdge:"<<k<<"-"<<"having distance:"<<min;
		visited[k]=1;
		visited[l]=1;
		final[k][l]=weight[k][l];
		final[l][k]=weight[l][k];
		total_cost=	total_cost+min;
		cout<<"\n Total cost is:"<<total_cost;
		cout<<"\n";
	}
}

int main()
{
	cout << "Telephone line........" << endl; 
	// prints minimum telephone line cost
	prim p;
	p.read();
	p.calmin();
	p.disp();
	return 0;
}
/*
//..............................................................................

//OUTPUT


newspaper boy's problem
Number of houses to be visited: 4
Enter the cost of travelling between two houses:
0   8   5   0
8   0   2   17
5   2   0   10
0   17  10   0

Edge:1-having distance:2
Edge:2-having distance:5
 Total cost is:7

Edge:2-having distance:10
 Total cost is:17

 To have the minimum cost the traveled path should be:
0	0	5	0	
0	0	2	0	
5	2	0	10	
0	0	10	0	

The total cost of traveling is: 17
*/
