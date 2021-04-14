#include <bits/stdc++.h>

using namespace std;

struct Segment {
    vector<int> tree;
    vector<int> lazy;
    int n;

    Segment(vector<int>& arr) {
        n = arr.size();
        tree = vector<int>(4 * n);
        lazy = vector<int>(4 * n);
        init(1, 0, n-1, arr);
    }

    int init(int nodeIndex, int nodeLeft, int nodeRight, vector<int>& arr) {
        if(nodeLeft == nodeRight) {
            tree[nodeIndex] = arr[nodeLeft];
            return;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        tree[nodeIndex] = init(2*nodeIndex, nodeLeft, mid, arr) + init(2*nodeIndex + 1, mid + 1, nodeRight, arr);
    }

    void update(int index, int val) {
        update(1, 0, n-1, index, val);
    }

    int update(int nodeIndex, int nodeLeft, int nodeRight, int index, int val) {
        if(index < nodeLeft || nodeRight < index) {
            return 0;
        }
        if(nodeLeft == nodeRight) {
            return tree[nodeIndex] = val;
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return tree[nodeIndex] = update(2*nodeIndex, nodeLeft, mid, index, val) + update(2*nodeIndex + 1, mid + 1, nodeRight, index, val);
    }

    int query(int arrLeft, int arrRight) {
        return query(1, 0, n-1, arrLeft, arrRight);
    }

    int query(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight) {
        propagate(nodeIndex, nodeLeft, nodeRight);

        if(arrRight < nodeLeft || nodeRight < arrLeft) {
            return 0;
        }
        if(arrLeft <= nodeLeft && nodeRight <= arrRight) {
            return tree[nodeIndex];
        }
        int mid = (nodeLeft + nodeRight) / 2;
        return query(2*nodeIndex, nodeLeft, mid, arrLeft, arrRight) + query(2*nodeIndex + 1, mid+1, nodeRight, arrLeft, arrRight);
    }

    void update_range(int arrLeft, int arrRight, int val) {
        update_range(1, 0, n-1, arrLeft, arrRight, val);
    }

    int update_range(int nodeIndex, int nodeLeft, int nodeRight, int arrLeft, int arrRight, int val) {
        propagate(nodeIndex, nodeLeft, nodeRight);

        if(arrRight < nodeLeft || nodeRight < arrLeft) {
            return tree[nodeIndex];
        }

        if(arrLeft <= nodeLeft && nodeRight <= arrRight) {
            lazy[nodeIndex] = val;
            return tree[nodeIndex] + lazy[nodeIndex] * (nodeRight - nodeLeft + 1);
        }
        int mid = (nodeLeft + nodeRight) / 2;

        return tree[nodeIndex] = update_range(nodeIndex*2, nodeLeft, mid, arrLeft, arrRight, val) + update_range(nodeIndex*2+1, mid+1, nodeRight, arrLeft, arrRight, val);
    }

    void propagate(int nodeIndex, int nodeRight, int nodeLeft) {
        if(lazy[nodeIndex] != 0) {
            tree[nodeIndex] += (nodeRight - nodeLeft + 1) * lazy[nodeIndex];
            if(nodeLeft != nodeRight) {
                lazy[nodeIndex*2] += lazy[nodeIndex];
                lazy[nodeIndex*2+1] += lazy[nodeIndex];
            }
            lazy[nodeIndex] = 0;
        }
    }
};
