//topological sort exists only for directed acyclic graph
#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<list<int>> adj;
	void topologicalSortUtil(int i, stack<int>& topoStack, vector<bool>& visited);
public:
	Graph(int v);
	void addEdge(int a, int b);
	void topologicalSort();
};

Graph::Graph(int v){
	this->v = v;
	adj.resize(v);
}

void Graph::addEdge(int a, int b){
	adj[a].push_back(b);
}

void Graph::topologicalSort(){
	stack<int> topoStack;
	vector<bool> visited(v, false);

	for(int i=0; i<v; i++){
		if(!visited[i])
			topologicalSortUtil(i, topoStack, visited);
	}

	while(!topoStack.empty()){
		cout << topoStack.top() << " ";
		topoStack.pop();
	}
}

void Graph::topologicalSortUtil(int i, stack<int>& topoStack, vector<bool>& visited){
	visited[i] = true;
	for(auto neighbor : adj[i]){
		if(!visited[neighbor])
			topologicalSortUtil(neighbor, topoStack, visited);
	}
	topoStack.push(i);
}

int main() {
	
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

	return 0;
}