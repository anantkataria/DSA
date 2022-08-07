#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<vector<int>> adj;
public:
	Graph(int v);
	void addEdge(int v, int w, int weight);
	void printGraph();
	void printDijkstra(vector<int>& dist);
	void dijkstra(int src);
	int minDistanceVertex(vector<int>& dist, vector<bool>& sptSet);
};

Graph::Graph(int v){
	this -> v = v;
	adj.resize(v, vector<int>(v, 0));
}

void Graph::addEdge(int v, int w, int weight){
	adj[v][w] = adj[w][v] = weight;
}

void Graph::printGraph() {
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
}

void Graph::printDijkstra(vector<int>& dist){
	cout << "Vertex\tDistance from Source\n"; 
	for(int i=0; i<v; i++)
		cout << i << "\t\t" << dist[i] << "\n";
}

int Graph::minDistanceVertex(vector<int>& dist, vector<bool>& sptSet){
	int min = INT_MAX;
	int min_index = -1;

	for(int i=0; i<v; i++){
		if(sptSet[i] == false && dist[i]<min)
			min = dist[i], min_index = i;
	}

	return min_index;
}

void Graph::dijkstra(int src){
	vector<int> dist(v, INT_MAX);
	vector<bool> sptSet(v, false);

	dist[src] = 0;

	for(int i=0; i<v; i++){
		int u = minDistanceVertex(dist, sptSet);
		sptSet[u] = true;

		for(int j=0; j<v; j++){
			if(sptSet[j]==false && adj[j][u] && dist[u] + adj[u][j] < dist[j])
				dist[j] = dist[u] + adj[j][u];
		}
	}

	printDijkstra(dist);
}

int main() {

	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(1, 2, 8);
	g.addEdge(2, 8, 2);
	g.addEdge(7, 8, 7);
	g.addEdge(7, 6, 1);
	g.addEdge(8, 6, 6);
	g.addEdge(6, 5, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);
	g.addEdge(5, 4, 10);

	// g.printGraph();
	g.dijkstra(0);

	return 0;
}