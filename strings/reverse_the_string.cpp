//https://www.interviewbit.com/problems/reverse-the-string/

string Solution::solve(string A) {
    int n = A.size();
    int i = 0;
    int j;
    string w, res;
    while (i < n) {
      while (i < n && A[i] == ' ') i++;
      j = i + 1;
      while (j < n && A[j] != ' ') j++;
      w = A.substr(i, j - i);
      if (res.size() == 0) res = w;
      else res = w + " " + res;
      i = j + 1;
    }
    return res; 
}