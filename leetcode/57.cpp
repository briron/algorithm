// 57. Insert Interval
// https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int> newInterval) {        
        vector<vector<int>> ret;
        int index = 0;

        while(index < intervals.size() && intervals[index][1] < newInterval[0]) {
            ret.push_back(intervals[index]);
            index += 1;
        }
        
        while(index < intervals.size() && intervals[index][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index += 1;
        }
        
        ret.push_back(newInterval);
        
        while(index < intervals.size()) {
            ret.push_back(intervals[index]);
            index += 1;
        }
        
        return ret;   
    }
};