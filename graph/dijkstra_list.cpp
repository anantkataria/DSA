#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode {
	int vertex; //destination vertex
	int dist; //distance of destination vertex from source vertex -> this will be used to make min heap
	MinHeapNode(int vertex, int dist){
		this->vertex = vertex;
		this->dist = dist;
	} 
};

class MinHeap {
public:
	int size;
	int capacity;
	//position of ith vertex (of graph) in minheap array will be pos[i]
	vector<int> pos; //this will be needed for decreaseKey() function
	vector<MinHeapNode*> array;

	MinHeap(int capacity);
	void minHeapify(int idx);
	void swap(int idx1, int idx2);
	MinHeapNode* extractMin();
	bool isEmpty();
	void decreaseKey(int vertex, int dist);
	bool isInMinHeap(int vertex);
	void printHeap();
	void printPos();
};

MinHeap::MinHeap(int capacity){
	pos.resize(capacity);
	size = 0;
	this->capacity = capacity;
	array.resize(capacity);
}

void MinHeap::swap(int idx1, int idx2){
	pos[array[idx1]->vertex] = idx2;
	pos[array[idx2]->vertex] = idx1;

	MinHeapNode* temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

void MinHeap::minHeapify(int idx){
	int smallest = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;

	if(left < size && array[left]->dist < array[smallest]->dist){
		smallest = left;
	}
	if(right < size && array[right]->dist < array[smallest]->dist){
		smallest = right;
	}
	if(smallest != idx){
		swap(smallest, idx);
		minHeapify(smallest);
	}
}

bool MinHeap::isEmpty(){
	return size == 0;
}

MinHeapNode* MinHeap::extractMin(){
	if(isEmpty())
		return NULL;

	pos[array[0]->vertex] = size-1;
	pos[array[size-1]->vertex] = 0;

	MinHeapNode* root = array[0];
	array[0] = array[size-1];

	size--;
	minHeapify(0);

	return root;
}

void MinHeap::decreaseKey(int vertex, int dist){
	int arrayIndex = pos[vertex];
	array[arrayIndex]->dist = dist;

	while(arrayIndex && array[arrayIndex]->dist < array[(arrayIndex-1)/2]->dist){
		swap(arrayIndex, (arrayIndex-1)/2);
		arrayIndex = (arrayIndex-1)/2;
	}
}

bool MinHeap::isInMinHeap(int vertex){
	if(pos[vertex] < size)
		return true;
	return false;
}

void MinHeap::printHeap() {
	int i=0;
	while(i < size){
		cout << i << " (" << array[i]->vertex << "," << array[i]->dist << ")\n";
		i++;
	}
}

void MinHeap::printPos(){
	cout << "pos : ";
	for(int i=0; i<capacity; i++)
		cout << pos[i] << " ";
	cout << "\n";
}

struct Node {
	int vertex;
	int weight;
	Node(int vertex, int weight){
		this->vertex = vertex;
		this->weight = weight;
	}
};

class Graph {
	int v;
	vector<list<Node*>> adj;
	void printDijkstra(vector<int>& dist);
public:
	Graph(int v);
	void addEdge(int vertex1, int vertex2, int weight);
	void printGraph();
	void dijkstraOptimized(int src);
};

Graph::Graph(int v){
	this->v = v;
	adj.resize(v);
}

void Graph::addEdge(int vertex1, int vertex2, int weight){
	Node* x = new Node(vertex1, weight);
	Node* y = new Node(vertex2, weight);
	adj[vertex1].push_back(y);
	adj[vertex2].push_back(x);
}

void Graph::printGraph() {
	for(int i=0; i<v; i++){
		cout << "vertex : " << i << ", connections : ";
		for(auto node : adj[i]){
			cout << "(" << node->vertex << "," << node->weight << "), ";
		}
		cout << endl;
	}
}

void Graph::printDijkstra(vector<int>& dist){
	cout << "Vertex\tDistance from Source\n"; 
	for(int i=0; i<v; i++)
		cout << i << "\t\t" << dist[i] << "\n";
}

void Graph::dijkstraOptimized(int src){
	vector<int> dist(v, INT_MAX);
	MinHeap minHeap(v);

	for(int i=0; i<v; i++){
		minHeap.array[i] = new MinHeapNode(i, dist[i]);
		minHeap.pos[i] = i;
	}
	minHeap.size = v; // initial size of min heap will be equal to number of vertex
	dist[src] = 0;
	minHeap.decreaseKey(src, dist[src]);

	while(!minHeap.isEmpty()){
		MinHeapNode* minHeapNode = minHeap.extractMin();
		int u = minHeapNode->vertex;
		for(auto ele : adj[u]){
			if(minHeap.isInMinHeap(ele->vertex) && dist[u]!=INT_MAX && ele->weight + dist[u] < dist[ele->vertex]){
				dist[ele->vertex] = dist[u] + ele->weight;
				//update distance value in min heap also
				minHeap.decreaseKey(ele->vertex, dist[ele->vertex]);
			}
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

	g.dijkstraOptimized(0);

	return 0;
}