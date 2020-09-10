#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();
    vector<int> leftmin(n, INT_MAX);
    vector<int> rightmin(n, INT_MAX);
    for(int i = 1 ; i < n ; ++i){
        leftmin[i] = min(leftmin[i-1], a[i-1]);
    }
    for(int i = n-2 ; i >= 0 ; --i){
        rightmin[i] = min(rightmin[i+1],a[i+1]);
    }
    for(int i = 0 ; i < n ; ++i){
        if(leftmin[i] < a[i] && rightmin[i] < a[i]){
            continue;
        }
        answer += 1;
    }
    return answer;
}