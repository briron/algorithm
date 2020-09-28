#include <bits/stdc++.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> dist(n+1, vector<int>(n+1));
    vector<vector<vector<int>>> g(n+1);
    for(int i = 0 ; i < fares.size(); ++i){
        g[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        g[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    for(int i = 1 ; i <= n ; ++i){
        int start = i;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, i});
        dist[start][start] = 0;
        while(pq.size() > 0){
            int here = pq.top()[0];
            int cost = pq.top()[1];
            pq.pop();
            for(int i = 0; i < g[here].size(); ++i){
                int there = g[here][i][0];
                int add = g[here][i][1];
                if(dist[start][there] < cost + add){
                    dist[start][there] = cost + add;
                    pq.push({cost+add, there});
                }
            }
        }
    }
    int ret = INT_MAX;
    for(int i = 1; i <= n; ++i){
        ret = min(ret, dist[s][i] + dist[i][a] + dist[i][b]);
    }

    return ret;


    
}