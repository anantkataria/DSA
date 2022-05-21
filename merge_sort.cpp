#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
	int l1 = mid-start+1;
	int l2 = end-mid;
	int arr1[l1];
	int arr2[l2];

	int count=start;
	for(int i=0; i<l1; i++)
		arr1[i] = arr[count++];
	for(int i=0; i<l2; i++)
		arr2[i] = arr[count++];

	int count1=0;
	int count2=0;
	count = start;

	while(count1 < l1 && count2 < l2){
		if(arr1[count1]<arr2[count2])
			arr[count++] = arr1[count1++];
		else
			arr[count++] = arr2[count2++];
	}

	while(count1<l1){
		arr[count++] = arr1[count1++];
	}

	while(count2<l2){
		arr[count++] = arr2[count2++];
	}
}

void mergesort(int arr[], int start, int end){
	if(start<end){
		int mid = start + (end-start)/2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

void printArray(int arr[], int n){
	cout << "Array after sorting:" << endl;
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];
	for(int i=0; i<n; i++)
		cin >> arr[i];

	mergesort(arr, 0, n-1);
	printArray(arr, n);

	return 0;
}