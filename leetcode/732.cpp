// 732. My Calendar III
// https://leetcode.com/problems/my-calendar-iii/

class MyCalendarThree {
public:
    map<int, int> m;
    
    int book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        int count = 0;
        int ret = 0;
        for(auto it = m.begin() ; it != m.end(); ++it) {
            count += it->second;
            ret = max(ret, count);
        }
        return ret;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */