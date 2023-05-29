#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph{
    unordered_map<int,list<int>> adj_list;

    public:

    void add_vertices(int a, int b){
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

};

int main(){
    int v,e;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>v>>e;
    Graph g;
    for (int i = 0; i < e; i++)
    {
        int a,b;
        cin>>a>>b;
        g.add_vertices(a,b);
    }
    g.display();
    
}