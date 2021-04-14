#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 에드몬드-카프 알고리즘(maxflow with bfs)
int networkFlow(int s, int t, vector<vector<int>>& graph) {
    int total = 0;
    vector<vector<int>> flow(graph.size(), vector<int>(graph.size()));
    while(true) {
        // 각 정점들의 이전 경로(정점)을 초기화한다
        vector<int> before(graph.size(), -1);
        // 시작접의 이전 경로는 자기 자신으로 한다
        before[s] = s;
        queue<int> q;
        q.push(s);
        // 더이상 방문할 곳이 없거나, sink 에 방몬할 때까지 BFS 를 동작시킨다
        while(q.size() > 0 && before[t] == -1) {
            int here = q.front();
            q.pop();
            for(int there = 0 ; there < graph[here].size(); ++there) {
                int cap = graph[here][there];
                if(before[there] == -1 && flow[here][there] < cap) {
                    before[there] = here;
                    q.push(there);
                }
            }
        }
        // 만약 sink 를 방문하지 않았다면 더 이상 증가경로가 없다는 의미이므로 종료한다
        if(before[t] == -1) {
            break;
        }
        // 증가경로에 흐를 수 있는 유량을 계산한다
        int amount = INT_MAX;
        for(int here = t; here != s ; here = before[here]) {
            amount = min(amount, graph[before[here]][here] - flow[before[here]][here]);
        }
        // 증가경로에 유량을 흘러보낸다
        for(int here = t; here != s ; here = before[here]) {
            flow[before[here]][here] += amount;
            flow[here][before[here]] -= amount;
        }
        total += amount;
    }
    return total;
} 

int main(){
    vector<vector<int>> g(4, vector<int>(4));
    g[0][1] = 1;
    g[0][2] = 3;
    g[1][2] = 1;
    g[1][3] = 2;
    g[2][3] = 1;
    cout << networkFlow(0, 3, g) << endl;

    return 0;
}