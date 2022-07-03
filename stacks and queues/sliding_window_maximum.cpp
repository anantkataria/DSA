//https://www.interviewbit.com/problems/sliding-window-maximum/
//https://leetcode.com/problems/sliding-window-maximum/discuss/65898/Clean-C%2B%2B-O(n)-solution-using-a-deque
//https://www.youtube.com/watch?v=DfljaUwZsOk

vector<int> Solution::slidingMaximum(const vector<int> &A, int k) {
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<A.size(); i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        
        if(i >= k-1)
            ans.push_back(A[dq.front()]);
    }
    
    return ans;
}
