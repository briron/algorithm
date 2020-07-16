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
