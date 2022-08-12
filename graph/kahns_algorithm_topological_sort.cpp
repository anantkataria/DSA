//topological sort exists only for directed acyclic graph
#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<list<int>> adj;
	void printTopologicalSort(vector<int>& topo);
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

void Graph::topologicalSort() {
	vector<int> inDegree(v, 0);
	vector<int> topo; //vector to store the answer;

	for(int i=0; i<v; i++){
		for(auto dest : adj[v]){
			inDegree[dest]++;
		}
	}

	queue<int> q;
	for(int i=0; i<v; i++){
		if(inDegree[i] == 0)
			q.push(i);
	}

	int count = 0; 
	while(!q.empty()){
		int u = q.front(); q.pop();
		topo.push_back(u);

		for(auto dest : adj[u]){
			inDegree[dest]--;
			if(inDegree[dest] == 0)
				q.push(dest);
		}

		count++;
	}

	if(count != v)
		cout << "Topological sort is not possible" << endl;
	else 
		printTopologicalSort(topo);
}

void Graph::printTopologicalSort(vector<int>& topo){
	for(auto i : topo)
		cout << i << " ";
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