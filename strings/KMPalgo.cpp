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