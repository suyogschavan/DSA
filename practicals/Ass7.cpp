#include <iostream>
#include <climits>
using namespace std;
class Graph
{
private:
    int vertices, edges;
    int adjacenyMatrix[100][100];

public:
    void create_graph()
    {
        cout<<" Enter the number of vertices of the Graph : ";
        cin>>vertices;
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                adjacenyMatrix[i][j]=0;
            }
        }

        cout<<" Enter the number of edges of the Graph : ";
        cin>>edges;
        for(int i=0;i<edges;i++)
        {
            int startVertex,endVertex;
            cout<<" Enter an edge (startVertex,endVertex) : ";
            cin>>startVertex>>endVertex;
            int weight;
            cout<<" Enter the weight of edge ( "<<startVertex<<" , "<<endVertex<<" ) : ";
            cin>>weight;
            adjacenyMatrix[startVertex][endVertex]=weight;
            adjacenyMatrix[endVertex][startVertex]=weight;
        }
        cout<<endl;
    }

    void display_graph()
    {
        cout<<" Displaying the Adjacency Matrix representation of the Graph :- "<<endl;
        cout<<endl;
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                cout<<adjacenyMatrix[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int selectMinVertex(int value[] ,bool setMST[])
    {
        int minimum=INT_MAX;
        int vertex;
        for(int i=0;i<vertices;i++)
        {
            if(setMST[i]==false && value[i]<minimum)
            {
                vertex=i;
                minimum=value[i]; 
            }
        }
        return vertex;
    }
    void primsAlgorithm()
    {
        int parent[vertices];
        int value[vertices];
        bool setMST[vertices];

        for(int i=0;i<vertices;i++)
        {
            value[i]=INT_MAX;
            setMST[i]=false;
        }

        parent[0]=-1;
        value[0]=0;

        for(int i=0;i<(vertices-1);i++)
        {
            int minWeightVertex=selectMinVertex(value,setMST);
            setMST[minWeightVertex]=true;

            for(int j=0;j<vertices;j++)
            {
                if(adjacenyMatrix[minWeightVertex][j]!=0 && setMST[j]==false && adjacenyMatrix[minWeightVertex][j]<value[j])
                {
                    value[j]=adjacenyMatrix[minWeightVertex][j];
                    parent[j]=minWeightVertex;
                }
            }
        }

        int MST[vertices][vertices];
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                MST[i][j]=0;
            }
        }

        for(int i=1;i<vertices;i++)
        {
            MST[parent[i]][i]=adjacenyMatrix[parent[i]][i];
            MST[i][parent[i]]=adjacenyMatrix[i][parent[i]];
        }

        cout<<endl;
        cout<<" Displaying the Minimum Spanning Tree (MST) of the Graph :- "<<endl;
        cout<<endl;
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                cout<<MST[i][j]<<"  "; 
            }
            cout<<endl;
        }
        cout<<endl;

        cout<<endl;
        int mstCost=0;
        for(int i=1;i<vertices;i++)
        {
            mstCost+=MST[parent[i]][i];
        }
        cout<<" The Cost of the Minimum Spanning Tree (MST) is : "<<mstCost<<endl;
    }
};
int main()
{
    Graph obj;
    int option;
    do
    {
        cout<<" -------------------Menu------------------- "<<endl;
        cout<<" 1. Create a Graph "<<endl;
        cout<<" 2. Display the Graph "<<endl;
        cout<<" 3. Prims Algorithm "<<endl;
        cout<<" 4. Exit "<<endl;
        cout<<"Enter the option : ";
        cin>>option;
        switch(option)
        {
            case 1:
                obj.create_graph();
                break;
            case 2:
                obj.display_graph();
                break;
            case 3:
                obj.primsAlgorithm();
                break;            
        }
        cout<<endl;
    }while(option>=1 && option<=3);
    return 0;
}