#include<bits/stdc++.h>
using namespace std;

#define v 4
# define INF 99999

void printSolution(int dist[][v]);

void floydWarshall(int graph[][v]){
	int dist[v][v], i, j, k;

	for(i=0; i<v; i++){
		for(j=0; j<v; j++){
			dist[i][j] = graph[i][j];
		}
	}

	for(k=0; k<v; k++){
		for(i=0; i<v; i++){
			for(j=0; j<v; j++){
				if(dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][v]) {
	for(int i=0; i<v; i++){
		for(int j=0; j<v; j++)
			if(dist[i][j] == INF) cout << "INF" << "\t";
			else cout << dist[i][j] << "\t";
		cout << endl;
	}

}

int main() {
	int graph[v][v] = {{0, 5, INF, 10},
					   {INF, 0, 3, INF},
					   {INF, INF, 0, 1},
					   {INF, INF, INF, 0}};
	floydWarshall(graph);
	return 0;
}