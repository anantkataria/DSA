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

bool isEmpty(TrieNode* root){
	for(int i=0; i<ALPHABET_SIZE; i++)
		if(root->children[i] != NULL)
			return false;
	return true;
}

TrieNode* remove(TrieNode* root, string key, int depth){
	if(!root)
		return NULL;

	if(depth == key.size()) {
		if(root->isEndOfWord)
			root->isEndOfWord = false;

		//if given character is not prefix of any other word
		if(isEmpty(root)){
			delete(root);
			root = NULL;
		}

		return root;
	}

	int index = key[depth] -  'a';
	root -> children[index] = remove(root->children[index], key, depth+1);

	if(isEmpty(root) && root->isEndOfWord == false){
		delete(root);
		root = NULL;
	}

	return root;
}

int main(){
	string keys[] = {
		"the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane"
	};
	int n = sizeof(keys)/sizeof(keys[0]);

	TrieNode* root = new TrieNode();

	for(int i=0; i<n; i++)
		insert(root, keys[i]);

	search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
	search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";
	remove(root, "heroplane", 0);
	search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
	search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";

	return 0;
}