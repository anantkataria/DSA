#include<bits/stdc++.h>
using namespace std;

class Edge {
public:
	int src, dest;
};

class Graph {
public:
	int v, e;
	Edge* edge;
};

Graph* createGraph(int v, int e){
	Graph* graph = new Graph();
	graph->v = v;
	graph->e = e;
	graph->edge = new Edge[e];
	return graph;
}

int find(int parent[], int i){
	if(parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void union_(int parent[], int x, int y){
	parent[x] = y;
}

bool isCycle(Graph* graph){
	int* parent = new int[graph->v];
	for(int i=0; i<graph->v; i++){
		parent[i] = -1;
	}

	for(int i=0; i<graph->e; i++){
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if(x == y)
			return true;

		union_(parent, x, y);
	}
	return false;
}

int main() {
	int v = 3;
	int e = 3;
	Graph* graph = createGraph(v, e);

	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;

	graph->edge[2].src = 0;
	graph->edge[2].dest = 2;

	if(isCycle(graph))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}