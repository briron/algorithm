// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret = vector<int>(nums.size());
        vector<int> sorted = vector<int>(nums.size());
        for(int i = 0 ; i < sorted.size() ; ++i) {
            sorted[i] = i;
        }
        merge_sort(0, sorted.size()-1, sorted, nums, ret);
        return ret;
    }
    
    void merge_sort(int start, int end, vector<int>& sorted, vector<int>& nums, vector<int>& ret) {
        if(start == end) {
            return;
        }
        int mid = (start+end)/2;
        merge_sort(start, mid, sorted, nums, ret);
        merge_sort(mid+1, end, sorted, nums, ret);
        merge(start, end, sorted, nums, ret);
    }
    
    void merge(int start, int end, vector<int>& sorted, vector<int>& nums, vector<int>& ret) {
        int mid = (start+end) / 2;
        vector<int> merged;
        int left_index = start;
        int right_index = mid+1;
        int added = 0;
        while(left_index <= mid && right_index <= end) {
            if(nums[sorted[left_index]] <= nums[sorted[right_index]]) {
                ret[sorted[left_index]] += added;
                merged.push_back(sorted[left_index]);
                ++left_index;
            }
            else{
                added += 1;
                merged.push_back(sorted[right_index]);
                ++right_index;
            }
        }
        
        while(left_index <= mid) {
            ret[sorted[left_index]] += added;
            merged.push_back(sorted[left_index]);
            ++left_index;
        }

        while(right_index <= end) {
            merged.push_back(sorted[right_index]);
            ++right_index;
        }
        
        for(int i = start ; i <= end ; ++i) {
            sorted[i] = merged[i-start];
        }   
    }
};