#include<bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<vector<int>> adj;
public:
	Graph(int v);
	void addEdge(int v, int w, int weight);
	void printGraph();
	int minKey(vector<int>& dist, vector<bool>& sptSet);
	void prim();
	void printMST(vector<int>& parent);
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

int Graph::minKey(vector<int>& dist, vector<bool>& sptSet){
	int min = INT_MAX;
	int min_index = -1;

	for(int i=0; i<v; i++){
		if(sptSet[i] == false && dist[i]<min)
			min = dist[i], min_index = i;
	}

	return min_index;
}

void Graph::prim(){
	//array to store constructed MST
	vector<int> parent(v);
	// key stores dat to pick minimum weight edge in cut
	vector<int> key(v, INT_MAX);
	// to represent set of vertices included in MST
	vector<bool> mstSet(v, false);

	key[0] = 0;
	parent[0] = -1; // first node is always root of MST

	for(int i=0; i<v; i++){
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for(int j=0; j<v; j++){
			if(adj[u][j] && mstSet[j]==false && adj[u][j] < key[j]){
				key[j] = adj[u][j];
				parent[j] = u;
			}
		}
	}
	printMST(parent);
}

void Graph::printMST(vector<int>& parent){
	cout << "Edge\tWeight\n";
	for(int i=1; i<v; i++)
		cout << parent[i] << " - " << i << "\t" << adj[i][parent[i]] << "\n";
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

	g.prim();

	return 0;
}