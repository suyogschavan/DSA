#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

class Graph{
    unordered_map<int, list<int>> adj_list;
    unordered_map<int,bool> visited;
    queue<int> q;

    public:
    void setEdges(int a, int b){
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    void BFS(int f){
        q.push(f);
        visited[f]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto i:adj_list[node]){
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
    Graph g;
    int n,e,f;
    cout<<"Enter the number of nodes and edges : ";
    cin>>n>>e;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        g.setEdges(a,b);
    }

    cout<<"Enter the first node to traverse by BFS : ";
    cin>>f;
    g.BFS(f);
    
}