//https://www.interviewbit.com/problems/zigzag-string/

string Solution::convert(string A, int B) {
    if(B <= 1){
        return A;
    }
    int n = A.size();
    vector<string> v(B, "");
    bool down = true;
    int count = 0;
    for(int i=0; i<n;){
        if(down){
            if(count < B){
                v[count] += A[i];
                count++;
                i++;
            }
            else{
                down = false;
                count -= 2;
            }
        }
        else {
            if(count >= 0){
                v[count] += A[i];
                count--;
                i++;
            }
            else{
                down = true;
                count += 2;
            }
        }
    }
    
    string ans = "";
    for(int i=0; i<v.size(); i++){
        ans += v[i];
    }
    
    return ans;
}
