// 31. Next Permutation
// https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        for(int i = nums.size() - 2; i >= 0 ; --i) {
            if(nums[i+1] > nums[i]) {
                pivot = i;
                break;
            }
        }
        reverse(nums.begin() + pivot + 1, nums.end());

        if(pivot == -1) {
            return;
        }

        for(int i = pivot + 1 ; i < nums.size(); ++i) {
            if(nums[pivot] < nums[i]) {
                swap(nums[pivot], nums[i]);
                return;
            }
        }
        return;
    }
};