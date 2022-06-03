//https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    vector<pair<string, int>> v;
    v.push_back(make_pair("I", 1));
    v.push_back(make_pair("IV", 4));
    v.push_back(make_pair("V", 5));
    v.push_back(make_pair("IX", 9));
    v.push_back(make_pair("X", 10));
    v.push_back(make_pair("XL", 40));
    v.push_back(make_pair("L", 50));
    v.push_back(make_pair("XC", 90));
    v.push_back(make_pair("C", 100));
    v.push_back(make_pair("CD", 400));
    v.push_back(make_pair("D", 500));
    v.push_back(make_pair("CM", 900));
    v.push_back(make_pair("M", 1000));
                                
    string ans = "";
    for(int i=v.size()-1; i>=0; i--){
        if(A/v[i].second){
            int count = A/v[i].second;
            while(count > 0){
                ans += v[i].first;
                count--;
            }
            A%=v[i].second;
        }
    }
    return ans;
}
