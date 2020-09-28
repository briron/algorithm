#include <bits/stdc++.h>

using namespace std;

void dfs(int here, int state, int parent, vector<int>& sales, vector<vector<int>>& g, vector<vector<int>>& dp){
    
    if(dp[here][state] != -1){
        return;
    }

    dp[here][state] = 0;
    if(state == 1){
        dp[here][state] += sales[here];
    }
    if(here != 0 && g[here].size() == 1){
        return;
    }
    int gap = INT_MAX;
    int sum = 0;
    bool inserted = false;

    for(int i = 0 ; i < g[here].size(); ++i){
        int there = g[here][i];
        if(there == parent){
            continue;
        }
        for(int j = 0 ; j < 2 ; ++j){
            dfs(there, j, here, sales, g, dp);
        }
        if(dp[there][0] >= dp[there][1]){
            inserted = true;
        }
        sum += min(dp[there][0], dp[there][1]);
        gap = min(gap, dp[there][1] - dp[there][0]);
    }

    dp[here][state] += sum;

    if(inserted == false && state == 0){
        dp[here][state] += gap;
    }

    return;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int N = sales.size();
    vector<vector<int>> g(N);
    for(int i = 0 ; i < links.size(); ++i){
        int a = links[i][0] - 1;
        int b = links[i][1] - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> dp(N, vector<int>(2, -1));

    dfs(0, 0, -1, sales, g, dp);
    dfs(0, 1, -1, sales, g, dp);

    return min(dp[0][0], dp[0][1]);
}