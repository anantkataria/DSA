#include<bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3){
	vector<int> ans;
	int x = 0, y = 0, z = 0;
	while(x<n1 && y<n2 && z<n3){
		if(arr1[x] == arr2[y] && arr2[y] == arr3[z]){
			ans.push_back(arr1[x]);
			x++;
			y++;
			z++;
		}
		else if(arr1[x] < arr2[y])
			x++;
		else if(arr2[y] < arr3[z])
			y++;
		else
			z++;
	}

	if(ans.empty())
		ans.push_back(-1);

	return ans;
}

int main(){

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	int arr1[n1], arr2[n2], arr3[n3];
	for(int i=0; i<n1; i++)
		cin >> arr1[i];
	for(int i=0; i<n2; i++)
		cin >> arr2[i];
	for(int i=0; i<n3; i++)
		cin >> arr3[i];

	vector<int> v = findCommonElements(arr1, arr2, arr3, n1, n2, n3);

	cout << "Common elements are:" << endl;
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	
	return 0;
}