#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    unordered_map<int, list<int>>adj_list;
    unordered_map<int,bool>visited;
    queue<int>q;

    public:
    void setEdge(int a, int b){
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); //Bcoz undirected graph
    }

    void display(){
        for(auto i:adj_list){
            cout<<i.first<<"-->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

    void print_BFS(int n){
        q.push(n);
        visited[n] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto l:adj_list[node]){
                if (!visited[l])
                {
                    q.push(l);
                    visited[l]=true;
                }
            }
            cout<<node<<" ";
        }
    }
};

int main(){
    int n, e;
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>e;

    Graph obj;

    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        obj.setEdge(a,b);
    }

    obj.display();
    int s;
    cin>>s;
    obj.print_BFS(s);
    
}