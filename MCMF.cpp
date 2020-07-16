#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> g(M+N+2);
    vector<vector<int>> c(M+N+2, vector<int>(M+N+2)); // capacity
    vector<vector<int>> d(M+N+2, vector<int>(M+N+2, INT_MAX)); // cost -> distance (최단거리의 거리의 개념과 같음) 
    vector<vector<int>> f(M+N+2, vector<int>(M+N+2)); // flow

    for(int i = 1 ; i <= N; ++i){
        int a;
        cin >> a;
        for(int j = 0 ; j < a; ++j){
            int m, cost;
            cin >> m >> cost;
            g[i].push_back(N+m);
            g[N+m].push_back(i);

            c[i][N+m] = 1;

            d[i][N+m] = cost;
            d[N+m][i] = -cost;
        }
    }

    int S = 0; // source
    int T = M+N+1; // sink
    for(int i = 1; i <= N; ++i){
        g[S].push_back(i);
        g[i].push_back(S);
        c[S][i] = 1;
        d[S][i] = 0;
        d[i][S] = 0;
    }
    for(int j = 1; j <= M ; ++j){
        g[T].push_back(N+j);
        g[N+j].push_back(T);
        c[N+j][T] = 1;
        d[T][N+j] = 0;
        d[N+j][T] = 0;
    }

    vector<int> dist(N+M+2, INT_MAX);
    vector<int> prev(N+M+2, -1);
    vector<int> inQ(N+M+2);
    int when = 1;
    dist[0] = 0;

    int mincost = 0;
    int maxflow = 0;

    while(true){
        queue<int> q;
        q.push(S);
        inQ[S] = when;
        for(int i = 1 ; i < N+M+2; ++i){
            dist[i] = INT_MAX;
            prev[i] = -1;
        }
        dist[S] = 0;

        while(q.size() > 0){
            int here = q.front();
            q.pop();
            inQ[here] = when - 1;
            for(int i = 0 ; i < g[here].size(); ++i){
                int there = g[here][i];
                if(c[here][there] - f[here][there] > 0 && dist[there] > dist[here] + d[here][there]){
                    dist[there] = dist[here] + d[here][there];
                    prev[there] = here;
                    if(inQ[there] < when){
                        q.push(there);
                        inQ[there] = when;
                    }
                }
            }
        }

        if(prev[T] == -1){
            break;
        }

        int flow = INT_MAX;

        for(int i = T; i != S; i = prev[i]){
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        for(int i = T; i != S; i = prev[i]){
            mincost += flow * d[prev[i]][i];
            f[prev[i]][i] += 1;
            f[i][prev[i]] -= 1;
        }

        maxflow += flow;
        when += 1;
    }

    cout << maxflow << endl << mincost << endl;

    return 0;

}