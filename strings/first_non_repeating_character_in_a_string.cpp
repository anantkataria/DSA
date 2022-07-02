//https://www.geeksforgeeks.org/given-a-string-find-its-first-non-repeating-character/

#include<bits/stdc++.h>
using namespace std;


/////////Method 1 : Hashmap and two times string traversal


/////////Method 2 : Hashmap and single string traversal
int solve(string& s){
	pair<int, int> arr[256] = {{0, 0}};
	for(int i=0; i<s.size(); i++){
		arr[s[i]].first += 1;
		arr[s[i]].second = i;
	}

	int ans = INT_MAX;
	for(int i=0; i<256; i++){
		if(arr[i].first == 1){
			ans = min(ans, arr[i].second);
		}
	}

	return ans;
}

//////// Connection : https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters
//////// connection : https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/

int main() {
	string s;
	getline(cin, s);
	cout << s[solve(s)];
	return 0;
}