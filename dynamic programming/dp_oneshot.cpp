#include<bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=oBt53YbR9Kk

// Problems :
// 1) Fibonacci
// 2) Grid Traveller
// 3) CanSum
// 4) HowSum
// 5) BestSum
// 6) CanConstruct
// 7) CountConstruct
// 8) AllConstruct

// Memoization Recipe
// 1) Make it Work. (come up with a brute force recursive approach)
//		- Visualize the problem as a tree (recursive tree)
//		- Implement the tree using recursion
//		- test it
// 2) Make it efficient. (Add memoization into the brute force to make it efficient)
//		- add a memo object
//		- add a base case to return memo values
//		- store return values into the memo


long long int fib(int n, unordered_map<int, long long int>& memo){
	if(memo.find(n) != memo.end()){
		return memo[n];
	}
	if(n <= 2)
		return 1;
	memo[n] = fib(n-1, memo) + fib(n-2, memo);
	return memo[n];
}
//Brute force : O(2^n) time, O(n) space;
//memoized : O(n) time, O(n) space;


unsigned long long int gridTraveller(int m, int n, unordered_map<string, unsigned long long int>& memo){
	string currentPair = to_string(m) + "," + to_string(n); 

	if(memo.find(currentPair) != memo.end())
		return memo[currentPair];

	if(m == 1 && n == 1)
		return 1;
	if(m == 0 || n == 0)
		return 0;

	memo[currentPair] = gridTraveller(m-1, n, memo) + gridTraveller(m, n-1, memo);
	return memo[currentPair];
}
//Brute force : O(2^(m+n)) time, O(m+n) space
//memoized : O(m*n) time, O(m+n) space <- why


bool canSum(int targetSum, vector<int> numbers, unordered_map<int, bool>& memo){
	if(memo.find(targetSum) != memo.end())
		return memo[targetSum];

	if(targetSum == 0)
		return true;
	if(targetSum < 0)
		return false;

	for(auto number : numbers){
		int remainder = targetSum - number;
		if(canSum(remainder, numbers, memo)){
			memo[targetSum] = true;
			return true;
		}
	}

	memo[targetSum] = false;
	return false;
}
//Brute force : if targetSum is m and numbers has n elements then O(n^m) time, O(m) space
//memoized : O(m*n) time, O(m) space


vector<int> howSum(int targetSum, vector<int> numbers, unordered_map<int, vector<int>>& memo) {
	if(memo.find(targetSum) != memo.end())
		return memo[targetSum];

	if(targetSum == 0)
		return vector<int>{};
	if(targetSum < 0)
		// ideally should return null
		// but this is workaround for c++
		return vector<int>{-1};

	for(auto number : numbers){
		int remainder = targetSum - number;
		vector<int> remainderResult = howSum(remainder, numbers, memo);
		if(!(remainderResult.size() == 1 && remainderResult[0] == -1)){
			remainderResult.push_back(number);
			memo[targetSum] = remainderResult;
			return remainderResult;
		}
	}

	// ideally should return null
	// but this is workaround for c++
	memo[targetSum] = vector<int>{-1};
	return vector<int>{-1};
}
//Brute force : if targetSum is m and numbers has n elements then O(n^m) time, O(m) space
//memoized : O(m*n) time, O(m^2) space

vector<int> bestSum(int targetSum, vector<int> numbers, unordered_map<int, vector<int>>& memo){
	if(memo.find(targetSum) != memo.end())
		return memo[targetSum];

	if(targetSum == 0)
		return vector<int>{};
	if(targetSum < 0)
		return vector<int>{-1};

	vector<int> ans;
	for(auto number : numbers){
		int remainder = targetSum - number;
		vector<int> remainderResult = bestSum(remainder, numbers, memo);
		if(!(remainderResult.size() == 1 && remainderResult[0] == -1)){
			remainderResult.push_back(number);
			if(ans.empty() || remainderResult.size() < ans.size())
				ans = remainderResult;
		}
	}

	if(ans.empty())
		ans.push_back(-1);
	memo[targetSum] = ans;
	return ans;
}
//Brute force : If targetSum is m and numbers has n elements then O(n^m) time, O(m^2) space <- why
//memoized : O(m*n) time, O(m^2) space


// helper method to check if word is a prefix for target string
bool isPrefix(string target, string word){
	for(int i=0; i<word.size(); i++){
		if(word[i] != target[i])
			return false;
	}
	return true;
}


bool canConstruct(string target, vector<string> wordBank, unordered_map<string, bool>& memo){
	if(memo.find(target) != memo.end())
		return memo[target];

	if(target == "")
		return true;

	for(auto word : wordBank){
		if(isPrefix(target, word)){
			string remainder = target.substr(word.size());
			if(canConstruct(remainder, wordBank, memo)){
				memo[target] = true;
				return true;
			}
		}
	}

	memo[target] = false;
	return false;
}
//Brute force : If target has length = m and wordbank has n words than O((n^m)*m) time, O(m^2) space
//memoized : O((m^2)*n) time, O(m^2) space


int countConstruct(string target, vector<string> wordBank, unordered_map<string, int>& memo){
	if(memo.find(target) != memo.end())
		return memo[target];

	if(target == "")
		return 1;

	int ans = 0;
	for(auto word : wordBank){
		if(isPrefix(target, word)){
			string remainder = target.substr(word.size());
			ans += countConstruct(remainder, wordBank, memo);
		}
	}

	memo[target] = ans;
	return ans;
}
//Brute force : If target has length = m and wordBank has n words than O((n^m)*m) time, O(m^2) space
//memoized : O((m^2)*n) time, O(m^2) space


vector<vector<string>> allConstruct(string target, vector<string> wordBank, unordered_map<string, vector<vector<string>>>& memo){
	if(memo.find(target) != memo.end())
		return memo[target];

	if(target == ""){
		vector<vector<string>> x(1, vector<string>());
		return x;
	}

	vector<vector<string>> ans;

	for(auto word : wordBank){
		if(isPrefix(target, word)){
			string remainder = target.substr(word.size());
			vector<vector<string>> remainderResult = allConstruct(remainder, wordBank, memo);
			if(!remainderResult.empty()){
				for(auto remainderWay : remainderResult){
					remainderWay.push_back(word);
					ans.push_back(remainderWay);
				}
			}
		}
	}

	memo[target] = ans;
	return ans;
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Tabulation Recipe
// Visualize the problem as a table
// Size the table based on the inputs
// Initialize the table with default values
// seed the trivial answer into the table - this is generally speaking a trivially small instance of input where we automatically know the answer
// Iterate through the table
// come up with some logic that fills further positions based on the current position



long long int fib(int n){
	vector<long long int> table(n+1, 0);

	// seed value
	table[1] = 1;

	for(int i=0; i<n; i++){
		if(i+1 <= n)
			table[i+1] += table[i];
		if(i+2 <= n)
			table[i+2] += table[i];
	}

	return table[n];
}
// O(n) time and space


long long int gridTraveller(int m, int n) {
	vector<vector<long long int>> table(m+1, vector<long long int>(n+1, 0));

	// seed value
	table[1][1] = 1;

	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if(j+1 <= n)
				table[i][j+1] += table[i][j];
			if(i+1 <= m)
				table[i+1][j] += table[i][j];
		}
	}

	return table[m][n];
}
// O(m*n) time, O(m*n) space


bool canSum(int targetSum, vector<int> numbers){
	vector<bool> table(targetSum+1, false);

	//seed
	table[0] = true;

	for(int i=0; i<targetSum; i++){
		if(table[i] == true){
			for(auto number : numbers){
				if(i+number <= targetSum)
					table[i+number] = true;
			}
		}
	}

	return table[targetSum];
}
// O(m*n) time, space O(m) space where m is targetsum and n is length of numbers array


vector<int> howSum(int targetSum, vector<int> numbers){
	// Initial values in the tables should be null. Here we are considering {-1} as null value
	vector<vector<int>> table(targetSum+1, vector<int>(1, -1));

	// seed
	table[0] = {};

	for(int i=0; i<targetSum; i++){
		// if element is not null
		if(!(table[i].size() == 1 && table[i][0] == -1)){
			for(auto number : numbers){
				if(i + number <= targetSum){
					vector<int> temp = table[i];
					temp.push_back(number);
					table[i+number] = temp;
				}
			}
		}
	}

	return table[targetSum];
}
// O(m*n) time, O(m^2) space


vector<int> bestSum(int targetSum, vector<int> numbers){
	vector<vector<int>> table(targetSum+1, vector<int>(1, -1));

	//seed
	table[0] = {};

	for(int i=0; i<targetSum; i++){
		if(!(table[i].size() == 1 && table[i][0] == -1)){
			for(auto number : numbers){
				// if value at i+number is null or array at i+number is longer than table[i].size()+1 than permit the change
				// better way to write this could be
				// if(isApproachable(i+number) && (hasSmallerLength() || isNull(i+number)))
				if(i+number <= targetSum && (table[i].size() + 1 < table[i+number].size() || (table[i+number].size() == 1 && table[i+number][0] == -1))){
					vector<int> temp = table[i];
					temp.push_back(number);
					table[i+number] = temp;
				}
				
			}
		}
	}

	return table[targetSum];
}
//O(m*n) time, O(m^2) space


bool canConstruct(string target, vector<string> wordBank){
	vector<bool> table(target.size()+1, false);

	//seed
	table[0] = true;

	for(int i=0; i<target.size(); i++){
		if(table[i] == true){
			string remainder = target.substr(i);
			for(auto word : wordBank){
				if(isPrefix(remainder, word)){
					table[i+word.size()] = true;
				}
			}
		}
	}

	return table[target.size()];
}
// time O(m*n), space O(m)


int countConstruct(string target, vector<string> wordBank){
	vector<int> table(target.size()+1, 0);

	//seed
	table[0] = 1;

	for(int i=0; i<target.size(); i++){
		if(table[i] != 0){
			string remainder = target.substr(i);
			for(auto word : wordBank){
				if(isPrefix(remainder, word)){
					table[i+word.size()] += table[i];
				}
			}
		}
	}

	return table[target.size()];
}
// O(m*n) time, O(m) space


vector<vector<string>> allConstruct(string target, vector<string> wordBank) {
	// empty 2d arrays will be the initial values for all indices
	vector<vector<vector<string>>> table(target.size()+1, vector<vector<string>>());

	//seed
	table[0].resize(1, vector<string>());

	for(int i=0; i<target.size(); i++){
		if(!table[i].empty()){
			string remainder = target.substr(i);
			for(auto word : wordBank){
				if(isPrefix(remainder, word)){
					for(auto way : table[i]){
						vector<string> temp = way;
						temp.push_back(word);
						table[i+word.size()].push_back(temp);
					}
				}
			}
		}
	}

	return table[target.size()];
}

// helper methods for traversing results
void traverse(vector<int> v){
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void traverse(vector<string> v){
	for(int i=0; i<v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void traverse2d(vector<vector<string>> v){
	if(v.empty())
		cout << "empty" << endl;

	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v[i].size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int main() {

	// fib
	// unordered_map<int, long long int> memo;
	// cout << fib(6, memo) << endl; //8
	// memo.erase(memo.begin(), memo.end());
	// cout << fib(7, memo) << endl; //13
	// memo.erase(memo.begin(), memo.end());
	// cout << fib(8, memo) << endl; //21
	// memo.erase(memo.begin(), memo.end());
	// cout << fib(50, memo) << endl; //12586269025

	// grid traveller
	// unordered_map<string, unsigned long long int> memo;
	// cout << gridTraveller(1, 1, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << gridTraveller(2, 3, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << gridTraveller(3, 2, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << gridTraveller(3, 3, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << gridTraveller(18, 18, memo) << endl;
	// memo.erase(memo.begin(), memo.end());

	// canSum
	// unordered_map<int, bool> memo;
	// cout << canSum(7, {2, 3}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canSum(7, {5, 3, 4, 7}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canSum(7, {2, 4}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canSum(8, {2, 3, 5}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canSum(300, {7, 14}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());

	// howSum
	// unordered_map<int, vector<int>> memo;
	// traverse(howSum(7, {2, 3}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(howSum(7, {5, 3, 4, 7}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(howSum(7, {2, 4}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(howSum(8, {2, 3, 5}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(howSum(300, {7, 14}, memo));
	// memo.erase(memo.begin(), memo.end());

	// bestSum
	// unordered_map<int, vector<int>> memo;
	// traverse(bestSum(7, {5, 3, 4, 7}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(bestSum(8, {2, 3, 5}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(bestSum(8, {1, 4, 5}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse(bestSum(100, {1, 2, 5, 25}, memo));
	// memo.erase(memo.begin(), memo.end());

	// canConstruct
	// unordered_map<string, bool> memo;
	// cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());

	// countConstruct
	// unordered_map<string, int> memo;
	// cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());
	// cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}, memo) << endl;
	// memo.erase(memo.begin(), memo.end());

	// allConstruct
	// unordered_map<string, vector<vector<string>>> memo;
	// traverse2d(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse2d(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse2d(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo));
	// memo.erase(memo.begin(), memo.end());
	// traverse2d(allConstruct("aaaaaaaaaaaaaaaaaaaaaaaaaaaz", {"a", "aa", "aaa", "aaaa", "aaaaa"}, memo));
	// memo.erase(memo.begin(), memo.end());


	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// fib
	// cout << fib(6) << endl;
	// cout << fib(7) << endl;
	// cout << fib(8) << endl;
	// cout << fib(50) << endl;

	// grid traveller
	// cout << gridTraveller(1, 1) << endl;
	// cout << gridTraveller(2, 3) << endl;
	// cout << gridTraveller(3, 2) << endl;
	// cout << gridTraveller(3, 3) << endl;
	// cout << gridTraveller(18, 18) << endl;

	// cansum
	// cout << canSum(7, {2, 3}) << endl;
	// cout << canSum(7, {5, 3, 4, 7}) << endl;
	// cout << canSum(7, {2, 4}) << endl;
	// cout << canSum(8, {2, 3, 5}) << endl;
	// cout << canSum(300, {7, 14}) << endl;

	// howSum
	// traverse(howSum(7, {2, 3}));
	// traverse(howSum(7, {5, 3, 4, 7}));
	// traverse(howSum(7, {2, 4}));
	// traverse(howSum(8, {2, 3, 5}));
	// traverse(howSum(300, {7, 14}));

	// bestSum
	// traverse(bestSum(7, {5, 3, 4, 7}));
	// traverse(bestSum(8, {2, 3, 5}));
	// traverse(bestSum(8, {1, 4, 5}));
	// traverse(bestSum(100, {1, 2, 5, 25}));

	// canConstruct
	// cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
	// cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
	// cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
	// cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}) << endl;

	// countConstruct
	// cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}) << endl;
	// cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
	// cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
	// cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
	// cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}) << endl;

	// allConstruct
	traverse2d(allConstruct("purple", {"purp", "p", "ur", "le", "purpl"}));
	traverse2d(allConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd", "ef", "c"}));
	traverse2d(allConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}));
	traverse2d(allConstruct("aaaaaaaaaaz", {"a", "aa", "aaa", "aaaa", "aaaaa"}));

	// Testing code
	// vector<vector<string>> x;
	// vector<vector<string>> y(1, vector<string>());
	// cout << x.size() << endl;
	// cout << y.size() << endl;
	// cout << x[0].size() << endl;
	// cout << x.empty();
	// cout << "Hello world!";
	return 0;
}