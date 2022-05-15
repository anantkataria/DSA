#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n){
	int low = 0;
	int mid = 0;
	int high = n-1;

	while(mid <= high){
		if(arr[mid] == 0){
			swap(arr[low++], arr[mid++]);
		}
		else if(arr[mid] == 1){
			mid++;
		}
		else{
			swap(arr[mid], arr[high--]);
		}
	}

	cout << "sorted array: " << endl;
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int i;
	cin >> i;

	int arr[i];
	for(int j=0; j<i; j++)
		cin >> arr[j];

	sort012(arr, i);

	return 0;
}