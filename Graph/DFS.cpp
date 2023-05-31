#include<iostream>
#include<map>
#include<list>
#include<stack>
using namespace std;

class Graph{ 
    map<int, list<int>> adj;
    map<int, bool> visited;

    public:
    void setEdges(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs_helper(int src, map<int,bool> &visited){
        // Recursive function that will traverse the graph

        cout<<src<<" ";
        visited[src]=true;
        // go to any nbr of that node that is not visited
        for(auto nbr:adj[src]){
            if(!visited[nbr]){
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(int starting){
        for(auto i:adj[starting]){
            int node = q.front();
            visited[starting] = false;
        }
        // call the helper function
        dfs_helper(starting, visited);
    }
};

int main(){
    Graph g;
    int v, e, st;
    cout<<"Enter the  vertices and edges of graph: ";
    cin>>v>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        g.setEdges(a,b);
    }
    
    cout<<"Enter the first node: ";
    cin>>st;
    g.dfs(st);
}
