#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template < typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adj_matrix;

    void addEdge(T a, T b, bool directed)
    {
        // directed = 0 -> undirected
        // directed = 1 -> directed
        adj_matrix[a].push_back(b);

        if (directed==0)
        {
            adj_matrix[b].push_back(a);
        }
        
    }

    void printAdjList(){
        for(auto i:adj_matrix){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main() {
    int n;
    cout<<"Enter the number of nodes ";
    cin>>n;
    int m;
    cout<<"Enter the number of edges ";
    cin>>m;

    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }

    g.printAdjList();
    
}