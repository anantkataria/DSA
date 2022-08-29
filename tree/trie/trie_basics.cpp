// Trie is an efficient information retrieval data structure. 
// Using Trie, search complexities can be brought to optimal limit (key length). 
// If we store keys in a binary search tree, a well balanced BST will need time proportional to M * log N, 
// where M is the maximum string length and N is the number of keys in the tree. 
// Using Trie, we can search the key in O(M) time. However, the penalty is on Trie storage requirements 

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

void display(TrieNode* root, char str[], int depth){
	if(root->isEndOfWord == true){
		str[depth] = '\0';
		cout << str << "\n";
	}
	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i] != NULL){
			str[depth] = i+'a';
			display(root->children[i], str, depth+1);
		}
	}
}

void display(TrieNode* root, string str){
	if(root->isEndOfWord == true){
		cout << str << "\n";
	}
	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i] != NULL){
			char child = i+'a';
			display(root->children[i], str + child);
		}
	}
}

void suggestionsRecur(TrieNode* root, string curr){
	if(root->isEndOfWord == true)
		cout << curr << "\n";

	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i] != NULL){
			char child = i+'a';
			suggestionsRecur(root->children[i], curr + child);
		}
	}
}

void printAutoSuggestions(TrieNode* root, string query){
	TrieNode* pCrawl = root;
	for(auto c : query){
		int index = c - 'a';
		if(pCrawl->children[index] == NULL){
			cout << "No words with the query found";
			return;
		}
		pCrawl = pCrawl -> children[index]; 
	}

	if(isEmpty(pCrawl) && pCrawl->isEndOfWord == true){
		cout << query << "\n";
		cout << "No other strings found";
		return;
	}

	suggestionsRecur(pCrawl, query);
}

int main(){
	string keys[] = {
		"the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane"
	};
	int n = sizeof(keys)/sizeof(keys[0]);

	TrieNode* root = new TrieNode();

	for(int i=0; i<n; i++)
		insert(root, keys[i]);

	// insert(root, "hello");
 //    insert(root, "dog");
 //    insert(root, "hell");
 //    insert(root, "cat");
 //    insert(root, "a");
 //    insert(root, "hel");
 //    insert(root, "help");
 //    insert(root, "helps");
 //    insert(root, "helping");

	// search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
	// search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";
	// remove(root, "heroplane", 0);
	// search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
	// search(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";

	// char str[20];
	// display(root, str, 0);

	// display(root, "");

	printAutoSuggestions(root, "bye");

	return 0;
}