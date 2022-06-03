//https://www.interviewbit.com/problems/power-of-2/

string divide(string A, int divisor){
    string ans;
    int idx = 0;
    int temp = A[idx] - '0';

    while(temp < divisor){
        temp = temp*10 + (A[++idx]-'0');
    }

    while(idx < A.size()){
        ans += (temp/divisor) + '0';
        temp = (temp%divisor)*10 + A[++idx]-'0';
    }

    if(ans.size() == 0){
        return "0";
    }
    return ans;
}

int Solution::power(string A) {

    if(A == "1") //VERY IMPORTANT EDGE CASE
        return 0;

    while((A[A.size()-1]-'0')%2 == 0){
        A = divide(A, 2);
    }

    if(A == "1")
        return 1;
    return 0;
}
