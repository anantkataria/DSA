#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<list<int>> adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void DFSUtil(int v, vector<bool>& visited);
	void DFS();
};

Graph::Graph(int v){
	this->v = v;
	adj.resize(v);
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::DFSUtil(int v, vector<bool>& visited){
	visited[v] = true;
	cout << v << " ";

	for(auto i = adj[v].begin(); i != adj[v].end(); i++){
		if(!visited[*i])
			DFSUtil(*i, visited);
	}
}

void Graph::DFS() {
	vector<bool> visited(v, false);
	for(int i=0; i<v; i++){
		if(!visited[i])
			DFSUtil(i, visited);
	}
}

int main() {

	Graph g(8);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(1, 6);
	g.addEdge(2, 3);
	g.addEdge(3, 0);
	g.addEdge(4, 5);
	g.addEdge(6, 5);
	g.addEdge(5, 7);

	vector<bool> visited(8, false);
	g.DFSUtil(1, visited);

	return 0;
}