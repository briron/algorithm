// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i = 0 ; i < nums.size() ; ++i) {
            hash.insert(nums[i]);
        }
        int ret = 0;
        for(auto it = hash.begin(); it != hash.end() ; ++it) {
            int here = *it;
            if(hash.find(here-1) == hash.end()) {
                int count = 1;
                while(hash.find(here+count) != hash.end()) {
                    count += 1;
                }
                ret = max(ret, count);
            }
        }
        return ret;
    }
};