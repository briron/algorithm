// 56. Merge Intervals
// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret = {intervals[0]};
        for(int i = 1; i < intervals.size() ; ++i) {
            if(intervals[i][0] <= ret.back()[1]) {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
                continue;
            }
            ret.push_back(intervals[i]);
        }
        return ret;
    }
};