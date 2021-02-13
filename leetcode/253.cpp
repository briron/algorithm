// 253. Meeting Rooms II
// https://leetcode.com/problems/meeting-rooms-ii/

// using map
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ret = 0;
        map<int,int> room_count;
        for(int i = 0 ; i < intervals.size(); ++i){
            room_count[intervals[i][0]] += 1;
            room_count[intervals[i][1]] -= 1;
        }
        int cur = 0;
        for(auto it = room_count.begin() ; it != room_count.end() ; ++it) {
            cur += it->second;
            ret = max(cur, ret);
        }
        return ret;
    }
};

/* using priority_queue
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ret = 0;
        priority_queue<int, vector<int>, greater<int>> open;
        priority_queue<int, vector<int>, greater<int>> close;
        
        for(int i = 0 ; i < intervals.size(); ++i){
            open.push(intervals[i][0]);
            close.push(intervals[i][1]);
        }

        int cur = 0;
        while(open.size() > 0){
            if(open.top() >= close.top()){
                cur -= 1;
                close.pop();
            }
            else{
                cur += 1;
                open.pop();
                ret = max(ret, cur);
            }
            
        }
        return ret;
    }
};
*/

/* using vector and sort
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ret = 0;
        priority_queue<int, vector<int>, greater<int>> open;
        priority_queue<int, vector<int>, greater<int>> close;
        
        for(int i = 0 ; i < intervals.size(); ++i){
            open.push(intervals[i][0]);
            close.push(intervals[i][1]);
        }

        int cur = 0;
        while(open.size() > 0){
            if(open.top() >= close.top()){
                cur -= 1;
                close.pop();
            }
            else{
                cur += 1;
                open.pop();
                ret = max(ret, cur);
            }
            
        }
        return ret;
    }
};
*/