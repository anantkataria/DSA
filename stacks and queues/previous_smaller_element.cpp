//https://www.interviewbit.com/problems/nearest-smaller-element/
// similar to : https://leetcode.com/problems/next-greater-element-i/

// monotonic stack problem similar to next greater element
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> s;
    vector<int> prevSmallerElement(A.size(), -1);
    for(int i = A.size()-1; i>=0; i--){
        while(!s.empty() && A[s.top()] > A[i]){
            prevSmallerElement[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }
    return prevSmallerElement;
}
