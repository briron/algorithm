#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int l, int r){
    int pos = l;
    int x = arr[r];
    for(int i = l ; i < r ; ++i){
        if(arr[i] < x){
            swap(arr[i], arr[pos]);
            ++pos;
        }
    }
    swap(arr[r], arr[pos]);
    return pos;
}

int kthsmallest(vector<int>& arr, int l, int r, int k){
    int pos = partition(arr, l, r);
    if(pos == k-1) return arr[pos];
    if(pos > k-1) return kthsmallest(arr, l, pos-1, k);
    return kthsmallest(arr, pos+1, r, k);
}


int main(){
    vector<int> arr = {4,3,2,1,0};
    cout << kthsmallest(arr, 0, 4, 2) << endl;
}


class Solution {
public:
    int calDist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    int partition(vector<vector<int>>& points, int l, int r){
        int dist = calDist(points[r]); int pos = l;
        for(int i = l ; i < r; ++i){
            if(calDist(points[i]) <= dist){
                swap(points[pos], points[i]);
                ++pos;
            }
        }
        swap(points[pos],points[r]);
        return pos;
    }
    int kthsmallest(vector<vector<int>>& points, int l, int r, int k){
        int pos = partition(points, l, r);
        if(pos == k-1) return pos;
        if(pos > k-1) return kthsmallest(points, l, pos-1, k);
        return kthsmallest(points, pos+1, r, k);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        kthsmallest(points, 0, points.size()-1, K);
        points.resize(K);
        return points;
    }
};