// https://leetcode.com/problems/3sum/

// O(n^2) time, O(logn) or O(n) space depending on sorting algorithm
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            
            // to handle duplicates
            if(i == 0 || nums[i] != nums[i-1]){
                int start = i+1;
                int end = nums.size()-1;
                while(start < end){
                    if(nums[i] + nums[start] + nums[end] == 0){
                        ans.push_back(vector<int>{nums[i], nums[start], nums[end]});
                        start++;
                        end--;
                        
                        // to handle duplicates
                        while(start < end && nums[start] == nums[start-1]){
                            start++;
                        }
                    }
                    else if(nums[i] + nums[start] + nums[end] < 0){
                        start++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }
        
        return ans;
    }
};


// Hashset + sorting(to handle duplicate elements) : O(n^2) time, O(n) space for hashset
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            
            // to handle repeated elements
            if(i == 0 || nums[i] != nums[i-1]){
                unordered_set<int> s;
                // -nums[i] = s.find(ele) + nums[j] => s.find(ele) = -nums[i]-nums[j]
                for(int j=i+1; j<nums.size(); j++){
                    if(s.find(-nums[i]-nums[j]) != s.end()){
                        ans.push_back(vector<int>{nums[i], nums[j], -nums[i]-nums[j]});
                        
                        // to skip repeated elements
                        int x = j+1;
                        while(x < nums.size() && nums[x] == nums[x-1]){
                            x++;
                        }
                        x--;
                        j = x;
                    }
                    s.insert(nums[j]);
                }
            }
        }
        
        return ans;
    }
};

// Approach 3: "No-Sort"






// variations

// https://leetcode.com/problems/3sum-smaller/solution/

// https://leetcode.com/problems/3sum-closest/solution/