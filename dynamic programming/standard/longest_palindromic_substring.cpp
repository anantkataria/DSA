#include<bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string s){
	vector<vector<bool>> table(s.size(), vector<bool>(s.size(), false));

	int start = 0;
	int maxLength = 1;

	// seeds
	for(int i=0; i<s.size(); i++){
		table[i][i] = true;
	}

	for(int i=0; i<s.size()-1; i++){
		if(s[i] == s[i+1]){
			table[i][i+1] = true;
			start = i;
			maxLength = 2;
		}
	}

	for(int len = 3; len <= s.size(); len++){
		for(int i = 0; i < s.size() - len + 1; i++){
			int j = i + len - 1;
			if(table[i+1][j-1] == true && s[i] == s[j]){
				table[i][j] = true;
				start = i;
				maxLength = len;
			}
		}
	}

	return s.substr(start, maxLength);
}

int main() {
	string s = "anamana";
	cout << longestPalindromicSubstring(s);
	return 0;
}