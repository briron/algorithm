// 295. Find Median from Data Stream
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
public:
    priority_queue<int> smallQueue;
    priority_queue<int, vector<int>, greater<int>> largeQueue;    
    
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        largeQueue.push(num);
        smallQueue.push(largeQueue.top());
        largeQueue.pop();

        while(largeQueue.size() < smallQueue.size()) {
            largeQueue.push(smallQueue.top());
            smallQueue.pop();
        }
    }
    
    double findMedian() {
        if(largeQueue.size() == smallQueue.size()){
            return ((double) largeQueue.top() + smallQueue.top() ) / 2; 
        }
        return (double) largeQueue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */