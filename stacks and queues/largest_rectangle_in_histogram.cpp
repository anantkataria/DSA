//https://www.youtube.com/watch?v=vhUxKxiconE
//https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

vector<int> findSmallerLeftIndex(vector<int>& A){
    stack<int> s;
    vector<int> result(A.size(), -1);
    for(int i=A.size()-1; i>=0; i--){
        while(!s.empty() && A[s.top()] > A[i]){
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return result;
}

vector<int> findSmallerRightIndex(vector<int>& A){
    stack<int> s;
    vector<int> result(A.size(), A.size());
    for(int i=0; i<A.size(); i++){
        while(!s.empty() && A[s.top()] > A[i]){
            result[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return result;
}

int Solution::largestRectangleArea(vector<int> &A) {
    vector<int> smallerLeftIndex(A.size(), 0);
    smallerLeftIndex = findSmallerLeftIndex(A);
    vector<int> smallerRightIndex(A.size(), 0);
    smallerRightIndex = findSmallerRightIndex(A);
    int largestArea = INT_MIN;
    for(int i=0; i<A.size(); i++){
        largestArea = max(largestArea, (smallerRightIndex[i]-smallerLeftIndex[i]-1)*A[i]);
    }
    return largestArea;
}