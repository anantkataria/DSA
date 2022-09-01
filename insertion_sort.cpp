#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n){
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}

void insertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int curr = arr[i];
		int j = i-1;

		while(j >= 0 && arr[j] > curr){
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = curr;
	}

	printArr(arr, n);
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	insertionSort(arr, n);
}