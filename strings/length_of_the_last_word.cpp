//https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A) {
    int p = A.size()-1;
    while(p>=0 && A[p] == ' '){
        p--;
    }

    int count = 0;
    while(p>=0 && A[p] != ' '){
        count++;
        p--;
    }

    return count;
}