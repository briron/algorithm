#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int networkFlow(int s, int t, vector<unordered_map<int,int>>& g){
    vector<unordered_map<int,int>> flow(g.size());
    int total = 0;
    while(true){
        vector<int> parent(g.size(), -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while(q.size() > 0 && parent[t] == -1){
            int here = q.front();
            q.pop();
            for(auto it = g[here].begin(); it != g[here].end(); ++it){
                int there = it->first;
                int cap = it->second;
                if(cap - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there]= here;
                }
            }
        }
        if(parent[t] == -1){
            break;
        }
        int amount = INT_MAX;
        for(int p = t; p != s; p = parent[p]){
            amount = min(amount, g[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = t; p != s; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        total += amount;
    }
    return total;
}


int main(){
    vector<unordered_map<int,int>> g(4);
    g[0][1] = 1;
    g[0][2] = 3;
    g[1][2] = 1;
    g[1][3] = 2;
    g[2][3] = 1;
    cout << networkFlow(0, 3, g) << endl;

    return 0;
}

int networkFlow(int s, int t, vector<unordered_map<int,int>>& g){
    int total = 0;
    vector<unordered_map<int,int>> flow(g.size());
    while(true){
        vector<int> parent(g.size(), -1);
        queue<int> q;
        parent[s] = s;
        q.push(s);
        while(q.size() > 0 && parent[t] == -1){
            int here = q.top();
            q.pop();
            for(auto it = g[here].begin(); it != g[here].end(); ++it){
                int there = it->first;
                int cap = g[here][there];
                if(cap - flow[here][there] > 0 && parent[there] == -1){
                    q.push(there);
                    parent[there] = here;
                }
            }
        }
        if(parent[t] != -1){
            break;
        }
        int amount = INT_MAX;
        for(int p = t ; parent[p] != s ; p = parent[p]){
            amount = min(amount, g[parent[p]][p] - flow[parent[p]][p]);
        }
        for(int p = t ; parent[p] != s ; p = parent[p]){
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
            total += amount;
        }
    }
    return total;
}