//https://www.interviewbit.com/problems/count-and-say/

string Solution::countAndSay(int A) {
    if(A == 1){
        return "1";
    }
    if(A == 2){
        return "11";
    }

    string str = "11";
    int cnt = 1;
    string tmp = "";
    for(int i=3; i<=A; i++){
        str += '$';
        cnt = 1;
        tmp = "";
        for(int j=1; j<str.size(); j++){
            if(str[j] != str[j-1]){
                tmp += cnt + '0';
                tmp += str[j-1];
                cnt = 1;
            }
            else
                cnt++;
        }
        str = tmp;
    }
    return str;
}
