#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
	map<int, list<int>> adj_list;
	map<int, bool> visited;
	queue<int> q;

	public:
	void setEdge(int a, int b){
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	void BFS(int st){
		q.push(st);
		visited[st]=true;

		while(!q.empty()){
			int node = q.front();
			q.pop();
			
			for(auto i:adj_list[node]){
				if(!visited[i]){
					q.push(i);
					visited[i] = true;
				}
			}
		cout<<node<<" ";
		}
	}
};


int main(){
	Graph obj;
	int n,e, starting;
	cout<<"Enter the number of nodes and edges: ";
	cin>>n>>e;
	
	for(int i=0; i<e; i++){
		int a,b;
		cin>>a>>b;
		obj.setEdge(a,b);
	}

	cout<<"Enter the starting node : ";
	cin>>starting;	
	obj.BFS(starting);

}
