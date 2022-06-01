#include<bits/stdc++.h>
using namespace std;

void partition(int arr[], int low, int high, int& i, int& j){

	if(high-low <= 1){
		if(arr[high] < arr[low]){
			swap(arr[high], arr[low]);
		}
		i = low;
		j = high;
		return;
	}

	int mid = low;
	int pivot = arr[high];

	while(mid <= high){
		if(arr[mid] < pivot){
			swap(arr[low++], arr[mid++]);
		}
		else if(arr[mid] == pivot){
			mid++;
		}
		else {
			swap(arr[mid], arr[high--]);
		}
	}

	i = low-1;
	j = high+1;
}

void quickSort3way(int arr[], int low, int high){
	if(low >= high)
		return;

	int i, j;

	partition(arr, low, high, i, j);

	quickSort3way(arr, low, i);
	quickSort3way(arr, j, high);
}

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
}

int main() {
	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	quickSort3way(arr, 0, n-1);

	printArray(arr, n);

	return 0;
}