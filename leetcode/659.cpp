// 659. Split Array into Consecutive Subsequences
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int pre = INT_MIN;
        int cur = nums[0];
        int cur_count = 0;
        vector<int> seq_count(3);
        for(int i = 0 ; i < nums.size() ; ++i) {
            cur = nums[i];
            cur_count = 1;
            while(i + 1 < nums.size() && nums[i+1] == cur) {
                cur_count += 1;
                i += 1;
            }
            if(pre+1 < cur) {
                if(seq_count[0] > 0 || seq_count[1] > 0) {
                    return false;
                }
                seq_count = {cur_count, 0, 0};
            }
            else {
                if(seq_count[0] + seq_count[1] > cur_count) {
                    return false;
                }
                seq_count = {max(0, cur_count - (seq_count[0] + seq_count[1] + seq_count[2])),
                             seq_count[0],
                             seq_count[1] + min(cur_count - (seq_count[0] + seq_count[1]), seq_count[2])};
            }
            pre = cur;
        }
        return seq_count[0] == 0 && seq_count[1] == 0;
    
    }
};