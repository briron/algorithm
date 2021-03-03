// 41. First Missing Positive
// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; ++i) {
            while(0 < nums[i] && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]) {
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        for(int i = 0 ; i < nums.size(); ++i) {
            if(nums[i] != i+1) {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};