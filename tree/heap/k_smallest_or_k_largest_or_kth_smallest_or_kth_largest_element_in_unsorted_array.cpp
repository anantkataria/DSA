// https://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
// https://www.geeksforgeeks.org/quickselect-algorithm/

#include<bits/stdc++.h>
using namespace std;

// approach 1: easiest way to this approach could be to sort the array and return relevant element(s). This is O(nlogn) process

// approach 2: use min heap or max heap as per requirement and extract first k elements. This is O(klog(n)) process

// approach 3: Quick select algorithm approach. It uses quick sort in a way that the output is generated in average O(n) time
// with worst case time complexity being O(n^2)

// here we will present approach 3

void printarr(int arr[], int n){
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int pivot(int arr[], int low, int high){
	int n = high - low + 1;
	int pivotIndex = rand() % n;
	swap(arr[low+pivotIndex], arr[high]);
	
	int pivot = arr[high];
	int i = low;
	for(int j=low; j<=high-1; j++){
		if(arr[j] < pivot){
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[high]);
	return i;
}

//for k largest -> do n - k smallest and then return elements greater equal to k
//for kth element -> return arr[pivotIndex]
void kSmallest(int arr[], int low, int high, int k, int n){
	if(low > high)
		return;

	int pivotIndex = pivot(arr, low, high);
	if( k-1 == pivotIndex){
		cout << k << " smallest elements are : ";
		for(int i=0; i<k; i++)
			cout << arr[i] << " ";
	}
	else if(k-1 > pivotIndex)
		kSmallest(arr, pivotIndex+1, high, k, n);
	else
		kSmallest(arr, low, pivotIndex-1, k, n);
}

int main() {
	int a[] = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50};
	//sorted : 1, 2, 3, 4, 5, 11, 15, 45, 50, 88, 96
	int n = sizeof(a)/sizeof(a[0]);

	int low = 0;
	int high = n-1;
	int k = 8;

	kSmallest(a, low, high, k, n);

	return 0;
}