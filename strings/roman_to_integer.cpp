int Solution::romanToInt(string A) {
     string s=A;
     if (s.empty()) { return 0; }
        unordered_map<char, int> mp { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int sum = mp[s.back()];
        for (int i = s.size() - 2; i >= 0; --i) {
            sum += mp[s[i]] >= mp[s[i + 1]] ? mp[s[i]] : -mp[s[i]];
        }
        return sum;
}