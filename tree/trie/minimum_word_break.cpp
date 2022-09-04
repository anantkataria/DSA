#include<bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode {
public:
	vector<TrieNode*> children;
	int isEndOfWord;
	TrieNode() {
		children.resize(ALPHABET_SIZE, nullptr);
		isEndOfWord = false;
	}
};

void insert(TrieNode* root, string key){
	TrieNode* pCrawl = root;

	for(auto c: key){
		int currIndex = c - 'a';
		if(pCrawl -> children[currIndex] == nullptr)
			pCrawl -> children[currIndex] = new TrieNode();
		pCrawl = pCrawl -> children[currIndex];
	}
	pCrawl -> isEndOfWord = true;
}

void minWordBreak(TrieNode* root, string key, int start, int* minBreak, int level = 0){
	TrieNode* pCrawl = root;

	if(start == key.length()){
		*minBreak = min(*minBreak, level-1);
		return;
	}

	for(int i=start; i<key.length(); i++){
		int currIndex = key[i] - 'a';
		if(pCrawl->children[currIndex] == nullptr)
			return;
		if(pCrawl->children[currIndex]->isEndOfWord)
			minWordBreak(root, key, i+1, minBreak, level+1);
		pCrawl = pCrawl -> children[currIndex];
	}
}

int main() {
	string dictionary[] = {
		"Cat", "Mat", "Ca", "Ma", "at", "C", "Dog", "og", "Do"
	};

	int n = sizeof(dictionary)/sizeof(dictionary[0]);
	TrieNode* root = new TrieNode();
	for(int i=0; i<n; i++){
		insert(root, dictionary[i]);
	}

	int minBreak = INT_MAX;
	minWordBreak(root, "CatMatat", 0, &minBreak, 0);
	cout << minBreak << endl;

	return 0;
}