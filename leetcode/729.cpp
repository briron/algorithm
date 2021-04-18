// https://leetcode.com/problems/my-calendar-i/
// 729. My Calendar I

class MyCalendar {
public:
    map<int, int> calendar;
    
    bool book(int start, int end) {
        auto st = calendar.lower_bound(start);
        auto et = calendar.lower_bound(end);
        if(st != et) {
            return false;
        }
        if(st == calendar.begin() || prev(st)->second <= start) {
            calendar[start] = end;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */