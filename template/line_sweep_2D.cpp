// 겹쳐진 사각형의 넓이를 구하기 위한
// segment tree 구현
#include <bits/stdc++.h>

using namespace std;

struct Node{
    vector<int> y_vals;
    int n;
    vector<vector<int>> line; // count, sum
    Node(vector<int>& y){
        y_vals = y;
        n = y.size();
        line.resize(4 * n, vector<int>(2));
    }
    int change(int y_start, int y_end, int state, int nodeLeft, int nodeRight, int nodeIndex){
        if(nodeRight < nodeLeft){
            return 0;
        }
        if(y_start <= y_vals[nodeLeft] && y_vals[nodeRight] < y_end){
            line[nodeIndex][0] += state;
        }
        else if(y_vals[nodeLeft] < y_end && y_vals[nodeRight] >= y_start){
            int nodeMid = (nodeLeft + nodeRight) / 2;
            int left = change(y_start, y_end, state, nodeLeft, nodeMid, nodeIndex * 2);
            int right = change(y_start, y_end, state, nodeMid+1, nodeRight, nodeIndex * 2 + 1);
            line[nodeIndex][1] = left + right;            
        }
        if(line[nodeIndex][0] > 0){
            return y_vals[nodeRight+1] - y_vals[nodeLeft]; 
        }
        return line[nodeIndex][1];
    }
    int change(int y_start, int y_end, int state){
        return change(y_start, y_end, state, 0, n-2, 1);
    }
};

// 위와 비스한 구현
struct Segment {
    unordered_map<int, int> y_to_idx;
    unordered_map<int, int> idx_to_y;
    vector<int> count;
    vector<int> sum;
    int n;
    
    Segment(set<int>& yset) {
        int idx = 0;
        for(auto it = yset.begin() ; it != yset.end() ; ++it) {
            y_to_idx[*it] = idx;
            idx_to_y[idx] = *it;
            idx += 1;
        }
        n = idx_to_y.size();
        count = vector<int>(4 * n);
        sum = vector<int>(4 * n);
    }

    void update(int ystart, int yend, int val) {
        int start_idx = y_to_idx[ystart];
        int end_idx = y_to_idx[yend] - 1;
        update(1, 0, n-2, start_idx, end_idx, val);
    }

    int update(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight, int val) {
        if(arrRight < nodeLeft || nodeRight < arrLeft) {
            return getSum(nodeIndex, nodeLeft, nodeRight);
        }
        if(arrLeft <= nodeLeft && nodeRight <= arrRight) {
            count[nodeIndex] += val;
        } else {
            int mid = (nodeLeft + nodeRight) / 2;
            int left = update(nodeIndex * 2, nodeLeft, mid, arrLeft, arrRight, val);
            int right = update(nodeIndex * 2 + 1, mid+1, nodeRight, arrLeft, arrRight, val);
            sum[nodeIndex] = left + right;
        }
        return getSum(nodeIndex, nodeLeft, nodeRight);
    }

    int getSum(int nodeIndex, int nodeLeft, int nodeRight) {
        if(count[nodeIndex] > 0) {
            return idx_to_y[nodeRight+1] - idx_to_y[nodeLeft];
        }
        return sum[nodeIndex];
    }

    int query() {
        return getSum(1, 0, n-2);
    }
};