#include<bits/stdc++.h>
using namespace std;

//priority queue is based on max heap data structure
//it takes log(n) time for push, pop
// max value access (minimum for min heap priority queue) can be done in constant time using front() function

int main() {

	priority_queue<int> maxPQ;
	priority_queue<int, vector<int>, greater<int>> minPQ;

	maxPQ.push(10);
	maxPQ.push(20);
	maxPQ.push(30);
	maxPQ.push(40);
	maxPQ.push(50);

	cout << "Max PQ :\n"; 
	while(!maxPQ.empty()){
		cout << maxPQ.top() << " ";
		maxPQ.pop();
	}
	cout << "\n\n";

	minPQ.push(10);
	minPQ.push(20);
	minPQ.push(30);	
	minPQ.push(40);
	minPQ.push(50);

	cout << "Min PQ :\n"; 
	while(!minPQ.empty()){
		cout << minPQ.top() << " ";
		minPQ.pop();
	}
	cout << "\n\n";

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPQ_pairType;
	minPQ_pairType.push({90, 10});
	minPQ_pairType.push({80, 10});
	minPQ_pairType.push({70, 10});
	minPQ_pairType.push({60, 5});
	minPQ_pairType.push({50, 5});

	cout << "Min PQ pair type:\n"; 
	while(!minPQ_pairType.empty()){
		cout << minPQ_pairType.top().first << " ";
		minPQ_pairType.pop();
	}
	cout << "\n";

	return 0;
}