#include <bits/stdc++.std>

using namespace std;

typedef long long ll;

vector<int> dijkstra(vector<vector<int>>& g, int start){
    vector<int> ret(g.size(),INT_MAX);
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    whlie(pq.size() > 0){
        int dist = pq.top().first; int here = pq.top().second; pq.pop();
        for(pair<int,int>& n : g[here]){
            int next = n.first; int d = n.second + dist;
            if(ret[next] > d) pq.push({d, next});
        }
    }
    return ret;
}

int main(){

}