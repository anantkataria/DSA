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

class subset {
public:
	int parent;
	int rank;
};

Graph* createGraph(int v, int e){
	Graph* graph = new Graph();
	graph->v = v;
	graph->e = e;
	graph->edge = new Edge[e];
	return graph;
}

int find(subset* s, int node){
	if(s[node].parent != node)
		s[node].parent = find(s, s[node].parent);
	return s[node].parent;
}

void Union(subset* s, int xroot, int yroot){
	if(s[xroot].rank < s[yroot].rank)
		s[xroot].parent = yroot;
	else if(s[xroot].rank > s[yroot].rank)
		s[yroot].parent = xroot;
	else {
		s[yroot].parent = xroot;
		s[xroot].rank++;
	}
}

bool isCycle(Graph* graph){
	int v = graph->v;
	int e = graph->e;

	subset* s = new subset[v];
	for(int i=0; i<v; i++){
		s[i].parent = i;
		s[i].rank = 0;
	}

	for(int i=0; i<e; i++){
		int x = find(s, graph->edge[i].src);
		int y = find(s, graph->edge[i].dest);

		if(x==y)
			return true;
		Union(s, x, y);
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
		cout << "Yessy";
	else
		cout << "No";

	return 0;
}