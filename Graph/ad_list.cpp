#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj_list;

    void setEdge(int a, int b){
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    void printEdges(){
        for( auto i:adj_list){
            cout<<i.first<<"->";
            for( auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int m,n;
    cout<<"Enter the number of nodes ";
    cin>>m;
    cout<<"Enter the number of edges ";
    cin>>n;

    Graph g;

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        g.setEdge(a, b);
    }

    g.printEdges();
    
}