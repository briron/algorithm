// 1. Two Sum
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numberMap;
        for(int i = 0 ; i < nums.size() ; ++i) {
            if(numberMap.find(target - nums[i]) != numberMap.end()){
                return {i, numberMap[target - nums[i]]};
            }
            numberMap[nums[i]] = i;
        }
        return {};
    }
};