#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    unordered_map<int, list<int>> adj_list;
    unordered_map<int, bool> visited;
    queue<int> q; 
    

    public:
    void initialize(int n){
        for(auto i:visited){
            i.second = false; 
        }
    }
    void insert_edge(int a, int b){
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
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

    void BFS(int src){
        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr:adj_list[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
            cout<<node<<" ";
        }
    }


};

int main(){
    int n,v;
    cout<<"Enter the number of nodes and edges"<<endl;
    cin>>n>>v;

    Graph g;
    for (int i = 0; i < v; i++)
    {
        int a,b;
        cin>>a>>b;
        g.insert_edge(a,b);
    }
    g.display();
    int src;
    cout<<"Enter the source node: ";
    cin>>src;
    g.BFS(src);
}