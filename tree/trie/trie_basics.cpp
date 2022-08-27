#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
public:
	vector<TrieNode*> children;
	bool isEndOfWord;
	TrieNode(){
		isEndOfWord = false;
		children.resize(ALPHABET_SIZE, nullptr);
	}
};

void insert(TrieNode *root, string key){
	TrieNode* pCrawl = root;

	for(int i=0; i<key.size(); i++){
		int index = key[i] - 'a';
		if(pCrawl->children[index] == nullptr)
			pCrawl->children[index] = new TrieNode();
		pCrawl = pCrawl -> children[index];
	}

	pCrawl->isEndOfWord = true;
}

bool search(TrieNode* root, string key){
	TrieNode* pCrawl = root;

	for(int i=0; i<key.size(); i++){
		int index = key[i] - 'a';
		if(pCrawl->children[index] == nullptr)
			return false;
		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

int main(){
	string keys[] = {
		"the", "a", "there", "answer", "any", "by", "bye", "their"
	};
	int n = sizeof(keys)/sizeof(keys[0]);

	TrieNode* root = new TrieNode();

	for(int i=0; i<n; i++)
		insert(root, keys[i]);

	search(root, "the") ? cout << "Yes\n" : cout << "No\n";
	search(root, "these") ? cout << "Yes\n" : cout << "No\n";
	search(root, "their") ? cout << "Yes\n" : cout << "No\n";
	search(root, "thaw") ? cout << "Yes\n" : cout << "No\n";

	return 0;
}