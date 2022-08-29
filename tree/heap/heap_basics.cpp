// https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-heap/
// https://www.geeksforgeeks.org/binary-heap/
// https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
// https://www.youtube.com/watch?v=VkKmmwzfIG4

//This is going to be a min heap
#include<bits/stdc++.h>
using namespace std;

class MinHeap {
	vector<int> arr;
	int capacity;
	int heapSize;
public:
	MinHeap(int capacity);
	void minHeapify(int);
	int parent(int i) {return (i-1)/2;}
	int left(int i) {return 2*i+1;}
	int right(int i) {return 2*i+2;}
	int extractMin();
	void decreaseKey(int i, int new_val);
	int getMin() {return arr[0];}
	void deleteKey(int i);
	void insertKey(int k);
};

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

MinHeap::MinHeap(int capacity){
	this->capacity = capacity;
	this->heapSize = 0;
	arr.resize(capacity);
}

void MinHeap::insertKey(int k){
	if(heapSize == capacity){
		cout << "Overflow: Could not insert key\n";
		return;
	}

	int i = heapSize;
	heapSize++;
	arr[i] = k;

	while(i!=0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i, int new_val){
	arr[i] = new_val;
	while(i!=0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

int MinHeap::extractMin() {
	if(heapSize <= 0)
		return INT_MAX;
	if(heapSize == 1){
		heapSize--;
		return arr[0];
	}
	int root = arr[0];
	arr[0] = arr[heapSize-1];
	heapSize--;
	minHeapify(0);

	return root;
}

//This function deletes key at index i
void MinHeap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	extractMin();
}

void MinHeap::minHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if(l < heapSize && arr[l] < arr[smallest])
		smallest = l;
	if(r < heapSize && arr[r] < arr[smallest])
		smallest = r;
	if(smallest != i){
		swap(&arr[i], &arr[smallest]);
		minHeapify(smallest);
	}
}

int main() {

	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}