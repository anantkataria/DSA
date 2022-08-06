// Note that the above code traverses only the vertices reachable from a given source vertex. The vertices may not be reachable from a given vertex (for example Disconnected graph). 

// To print all the vertices, we can modify the BFS function to do traversal starting from all nodes one by one (Like the DFS modified version). 

#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<list<int>> adj;
public:
	Graph(int v);
	void addEdge(int v, int w);
	void BFS(int s);
};

Graph::Graph(int v){
	this->v = v;
	adj.resize(v);
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph::BFS(int s){
	vector<bool> visited(v, false);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while(!q.empty()){
		s = q.front();
		cout << s << " ";
		q.pop();

		for(auto adjacent : adj[s]){
			if(!visited[adjacent]){
				visited[adjacent] = true;
				q.push(adjacent);
			}
		}
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

	g.BFS(1);

	return 0;
}