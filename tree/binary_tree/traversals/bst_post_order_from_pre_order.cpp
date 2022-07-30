#include<bits/stdc++.h>
using namespace std;

void recur(int pre[], int mi, int ma, int& index, int n){
	if(index == n)
		return;
	if(pre[index] < mi || pre[index] > ma)
		return;

	int val = pre[index];
	index = index + 1;
	recur(pre, mi, val, index, n);
	recur(pre, val, ma, index, n);
	cout << val << " ";
}

void findPostOrder(int pre[], int n){
	int index = 0;
	recur(pre, INT_MIN, INT_MAX, index, n);
}

int main() {

	int pre[] = {4, 2, 1, 3, 6, 5, 7};
	int n = 7;

	findPostOrder(pre, n);

	return 0;
}