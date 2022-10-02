// https://leetcode.com/problems/regular-expression-matching/


// Memoization
// https://www.youtube.com/watch?v=HAA8mgxlov8
class Solution {
public:
    
    bool recur(string s, string p, int i, int j, unordered_map<string, bool>& memo){
        string key = to_string(i) + "," + to_string(j);
        if(memo.find(key) != memo.end())
            return memo[key];
        
        if(i >= s.size() && j >= p.size())
            return true;
        if(j >= p.size())
            return false;
        
        bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
        
        if(j+1 < p.size() && p[j+1] == '*'){
            memo[key] =  (recur(s, p, i, j+2, memo) || (match && recur(s, p, i+1, j, memo)));   
            return memo[key];
        }
        
        if(match){
            memo[key] = recur(s, p, i+1, j+1, memo);
            return memo[key];
        }
            
        memo[key] = false;
        return false;
    }
    
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return recur(s, p, 0, 0, memo);
    }
}


// Tabulation
// https://www.youtube.com/watch?v=l3hda49XcDE
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> table(s.size()+1, vector<bool>(p.size()+1, false));
        
        //seed
        table[0][0] = true;
        
        for(int j=2; j<=p.size(); j++){
            table[0][j] = p[j-1] == '*' && table[0][j-2];
        }
        
        for(int j=1; j<=p.size(); j++){
            for(int i=1; i<=s.size(); i++){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    table[i][j] = table[i-1][j-1];
                else if(p[j-1] == '*'){
                    table[i][j] = table[i][j-2] || (s[i-1] == p[j-2] || p[j-2]=='.') && table[i-1][j];
                }
            }
        }
        
        return table[s.size()][p.size()];
    }
};