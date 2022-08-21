// https://leetcode.com/problems/longest-valid-parentheses/submissions/

// DP
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(), 0);
        int ans = 0;
        
        for(int i=1; i<s.size(); i++){
            if(s[i] == ')'){
                if(s[i-1] == '(')
                    dp[i] = (i-2>=0?dp[i-2]:0) + 2;
                else if((i-dp[i-1]-1) >= 0 && s[i-dp[i-1]-1] == '(')
                        dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
                
                ans = max(ans, dp[i]);
            }
            
        }
        
        return ans;
    }
};


//Stack
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i=0; i<s.size(); i++){
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                    if(st.empty())
                        st.push(i);
                    else {
                        ans = max(ans, i-st.top());
                    }
                }
            }
            else {
                st.push(i);
            }
        }
        
        return ans;
    }
};

//two pointer
public class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right >= left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left >= right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}