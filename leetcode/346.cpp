// 346. Moving Average from Data Stream
// https://leetcode.com/problems/moving-average-from-data-stream/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int maxSize;
    int sum = 0;
    
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        while(q.size() >= maxSize) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return (double)sum/(int)q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */