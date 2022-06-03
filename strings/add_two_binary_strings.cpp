string Solution::addBinary(string A, string B) {
    int m = A.size();
    int n = B.size();

    if(m > n){
        int count = m-n;
        while(count > 0){
            B = "0" + B;
            count--;
        }
        n = m;
    }
    else if(n > m){
        int count = n-m;
        while(count > 0){
            A = "0" + A;
            count--;
        }
        m = n;
    }

    m--;
    int carry = 0;
    string ans = "";
    while(m >= 0){
        int val = (A[m]-'0') + (B[m]-'0') + carry;
        int sum = val % 2;
        carry = val / 2;
        ans = to_string(sum) + ans;
        m--;
    }

    if(carry == 1){
        ans = "1" + ans;
    }

    return ans;
}
