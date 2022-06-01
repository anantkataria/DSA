#include<bits/stdc++.h>
using namespace std;

int main() {
	
	unordered_map<string, double> umap1;

	//insertion in unordered_map using [] operator
	umap1["pi"] = 3.14;
	umap1["root2"] = 1.414;
	umap1["root3"] = 1.732;
	umap1["log10"] = 2.302;
	umap1["loge"] = 1;

	//insertion using insert function
	umap1.insert(make_pair("e", 2.718));

	//finding a key and printing its value
	string key = "pi";
	if(umap1.find(key) == umap1.end()){
		cout << "Key not found" << endl;
	}
	else {
		cout << key << " Found. Value = " << umap1[key] << endl;
	}

	unordered_map<string, double>::iterator itr;
	for(itr = umap1.begin(); itr != umap1.end(); itr++){
		cout << itr->first << " " << itr->second << endl;
	}
 
	return 0;
}