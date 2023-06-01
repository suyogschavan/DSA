#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
    map<int, list<int>> adj;
    map<int, bool> visited;
    queue<int> q;

    public:
    void setEdge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void bfs(int start){
        q.push(start);
        visited[start]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i: adj[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }

            }
                cout<<node<<" ";
        }
    }
};

int main(){
    int n, m, k;
    cout<<"Enter the number of nodes and edges: "<<endl;
    cin>>n>>m;
    Graph g;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        g.setEdge(a, b);
    }

    cout<<"From which node you wan't to start BFS traversal?"<<endl;
    cin>>k;
    g.bfs(k);
    
}