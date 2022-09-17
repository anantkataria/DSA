// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// How to use lps[] to decide next positions (or to know a number of characters to be skipped)?

// We start comparison of pat[j] with j = 0 with characters of current window of text.
// We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
// When we see a mismatch
// We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
// We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
// From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. Let us consider above example to understand this.

#include<bits/stdc++.h>
using namespace std;

void makelps(string pat, vector<int>& lps){
	lps[0] = 0;

	if(lps.size() <= 1)
		return;

	int i = 1;
	int prevlps = 0;
	while(i < pat.size()){
		if(pat[i] == pat[prevlps]){
			lps[i] = prevlps + 1;
			prevlps++;
			i++;
		}
		else {
			if(prevlps != 0){
				prevlps = lps[prevlps-1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}

}

void kmp(string txt, string pat){
	int m = pat.size();
	int n = txt.size();

	vector<int> lps(m);
	makelps(pat, lps);

	int i = 0;
	int j = 0;

	while(i < n){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}else {
			if(j != 0){
				j = lps[j-1];
			}else {
				i++;
			}
		}

		if(j == m){
			cout << "Pattern Found at : " << i-j << endl;
			j = lps[j-1];
		}
	}
}

int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";
	kmp(txt, pat);

	return 0;
}