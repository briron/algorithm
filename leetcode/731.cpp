// 731. My Calendar II
// https://leetcode.com/problems/my-calendar-ii/

class MyCalendarTwo {
public:
    map<int, int> calendar;
    
    bool book(int start, int end) {
        calendar[start] += 1;
        calendar[end] -= 1;
        int cur = 0;
        for(auto it = calendar.begin(); it != calendar.end(); ++it) {
            cur += it->second;
            if(cur > 2) {
                calendar[start] -= 1;
                calendar[end] += 1;
                if(calendar[start] == 0) {
                    calendar.erase(start);
                }
                if(calendar[end] == 0) {
                    calendar.erase(end);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */