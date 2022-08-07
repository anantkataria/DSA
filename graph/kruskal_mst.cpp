#include<bits/stdc++.h>
using namespace std;

class DSU {
	int* parent;
	int* rank;
public:
	DSU(int n){
		parent = new int[n];
		rank = new int[n];

		for(int i=0; i<n; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i){
		if(parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y){
		int p1 = find(x);
		int p2 = find(y);

		if(p1 != p2){
			if(rank[p1] < rank[p2]){
				parent[p1] = p2;
				rank[p2] += rank[p1];
			}
			else {
				parent[p2] = p1;
				rank[p1] += rank[p2];
			}
		}
	}
};

class Graph {
	vector<vector<int>> edgelist;
	int v;
public:
	
	Graph(int v) {this -> v = v;}
	
	void addEdge(int x, int y, int w){
		edgelist.push_back({w, x, y});
	}

	void kruskal() {
		sort(edgelist.begin(), edgelist.end());
		DSU s(v);
		int ans = 0;
		cout << "edges in the MST" << endl;
		for(auto edge : edgelist){
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];

			if(s.find(x) != s.find(y)){
				s.unite(x, y);
				ans += w;
				cout << x << " -- " << y << " == " << w << endl;
			}
		}
		cout << "minimum cost spanning tree cost :" << ans;
	}	
};

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

	g.kruskal();
	return 0;
}