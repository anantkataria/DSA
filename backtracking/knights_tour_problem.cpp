#include<bits/stdc++.h>
using namespace std;

vector<int> rdir = {2, 1, -2, -1, -2, -1,  2,  1};
vector<int> cdir = {1, 2,  1,  2, -1, -2, -1, -2};

bool isPossible(int r, int c, vector<vector<int>>& board){
	if(r < board.size() && c < board[0].size() && r >= 0 && c >= 0 && board[r][c] == -1)
		return true;
	return false;
}

bool recur(int r, int c, vector<vector<int>>& board, int valuesFilled){
	// base case when we have covered all cells of the board
	if(valuesFilled == board.size()*board.size())
		return true;

	for(int i=0; i<8; i++){
		int newr = r + rdir[i];
		int newc = c + cdir[i];
		if(isPossible(newr, newc, board)) {
			board[newr][newc] = valuesFilled;
			if(recur(newr, newc, board, valuesFilled+1)){
				return true;
			}
			else {
				board[newr][newc] = -1;
			}	
		}
	}

	return false;
}

void print2d(vector<vector<int>> table){
	for(int i=0; i<table.size(); i++) {
		for(int j=0; j<table[0].size(); j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n = 8;
	vector<vector<int>> board(n, vector<int>(n, -1));
	board[0][0] = 0;
	if(recur(0, 0, board, 1)){
		print2d(board);
	}

	cout << "Hello world";

	return 0;
}