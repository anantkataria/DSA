//https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/
//https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/

string Solution::solve(string A) {
    string ans = "";
    int freq[26] = {0};
    queue<char> q;
    
    for(int i=0; i<A.size(); i++){
        q.push(A[i]);
        freq[A[i]-'a']++;
        while(!q.empty()){
            if(freq[q.front()-'a'] > 1){
                q.pop();
            }
            else {
                ans += q.front();
                break;
            }
        }
        
        if(q.empty()){
            ans += "#";
        }
    }
    
    return ans;
}
 