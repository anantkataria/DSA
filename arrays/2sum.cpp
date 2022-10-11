// https://leetcode.com/problems/two-sum/

// O(n^2), O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        
        return vector<int>{};
    }
};

// O(n), O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        
        for(int i=0; i<nums.size(); i++){
            if(m.find(target-nums[i]) != m.end())
                return vector<int>{m[target-nums[i]], i};
            m[nums[i]] = i;
        }
        
        return vector<int>{};
    }
};



// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// O(n), O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        int end = numbers.size()-1;
        while(start < end){
            if(numbers[start] + numbers[end] == target){
                return vector<int>{start+1, end+1};
            }
            else if(numbers[start] + numbers[end] < target)
                start++;
            else
                end--;
        }
        
        return vector<int>{};
    }
};


// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/