#include<bits/stdc++.h>
using namespace std;

bool isSafe(int r, int c, vector<vector<bool>>& table){
	int i = r, j = c-1;
	while(j >= 0){
		if(table[i][j])
			return false;
		j--;
	}

	i = r-1, j = c-1;
	while(i >= 0 && j >= 0){
		if(table[i][j])
			return false;
		i--;
		j--;
	}

	i = r+1, j = c-1;
	while(i < table.size() && j >= 0){
		if(table[i][j])
			return false;
		i++;
		j--;
	}

	return true;
}

bool recur(int col, vector<vector<bool>>& table, int queensLeft){
	// base case if all queens are placed correctly 
	if(queensLeft == 0)
		return true;

	for(int i=0; i<table.size(); i++){
		if(isSafe(i, col, table)){
			table[i][col] = true;
			if(recur(col+1, table, queensLeft-1))
				return true;
			else
				table[i][col] = false;
		}

	}
	return false;
}

void print2d(vector<vector<bool>> table){
	for(int i=0; i<table.size(); i++) {
		for(int j=0; j<table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n = 5;
	vector<vector<bool>> table(n, vector<bool>(n, false));

	if(recur(0, table, n)){
		print2d(table);
	}

	return 0;
}