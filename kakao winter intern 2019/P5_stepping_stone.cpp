#include <bits/stdc++.h>

using namespace std;

bool cross(int mid, vector<int>& stones, int k){
    int count = 0;
    for(int i = 0 ; i < stones.size(); ++i){
        if(stones[i] < mid){
            count += 1;
            if(count >= k){
                return false;
            }
        }
        else{
            count = 0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int lo = 0;
    int hi = INT_MAX - 1;
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        if(cross(mid, stones, k)){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    return lo;
}