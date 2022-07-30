// catalan number is a sequence of natural numbers that occurs in many interesting 
// counting problems like:
// 1) count number of expressions containing n pairs of parantheses which are correctly 
//    matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
// 2) count the number of possible binary search trees with n keys
// 3) count the number of full binary trees with n+1 leaves

//https://www.geeksforgeeks.org/program-nth-catalan-number/

//further optimization possible here

#include<bits/stdc++.h>
using namespace std;

int catalan(int n){

	if(n <= 1)
		return 1;

	int arr[n+1] = {0};
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=0; j<i; j++){
			arr[i] += arr[j]*arr[i-j-1];
		}
	}

	return arr[n];
}

int main() {
	for(int i=0; i<=10; i++)
		cout << catalan(i) << endl;
	return 0;
}