// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        kthSmallest(points, 0, points.size()-1, K);
        vector<vector<int>> ret(K);
        ret.assign(points.begin(), points.begin() + K);
        return ret;
    }
    
    int kthSmallest(vector<vector<int>>& points, int start, int last, int K) {
        int pos = partition(points, start, last);
        if(pos == K-1){
            return pos;
        }
        if(pos > K-1) {
            return kthSmallest(points, start, pos-1, K);
        }
        return kthSmallest(points, pos+1, last, K);
    }
    
    int partition(vector<vector<int>>& points, int start, int last) {
        int x = getDistance(points[last]);
        int pos = start;
        for(int i = start ; i < last ; ++i) {
            if(x >= getDistance(points[i])) {
                swap(points[i], points[pos]);
                pos += 1;
            }
        }
        swap(points[last], points[pos]);
        return pos;
    }
    
    int getDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};