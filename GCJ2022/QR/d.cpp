#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

// self, sum
pair<ll, ll> dfs(ll here, ll parent, vector<ll>& funs, vector<vector<ll>>& graph) {
    ll self = funs[here];
    ll sum = 0;
    ll minChild = LLONG_MAX;

    for(int i = 0 ; i < graph[here].size() ; ++i) {
        ll there = graph[here][i];
        if(there == parent) {
            continue;
        }
        pair<ll, ll> p = dfs(there, here, funs, graph);
        sum += p.second;
        minChild = min(minChild, p.first);
    }

    if(minChild == LLONG_MAX) {
        minChild = 0;
    }

    sum += max((ll)0, self - minChild);
    return make_pair(max(self, minChild), sum);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<ll> funs(N+1);
        for(int i = 1 ; i <= N ; ++i) {
            cin >> funs[i];
        }
        vector<ll> parents(N+1);
        vector<vector<ll>> graph(N+1);
        for(int i = 1 ; i <= N ; ++i) {
            cin >> parents[i];
            graph[parents[i]].push_back(i);
        }

        ll ret = 0;
        for(int i = 0 ; i < graph[0].size() ; ++i) {
            int root = graph[0][i];
            ret += dfs(root, 0, funs, graph).second;
        }


        cout << "Case #" << t << ": " << ret << endl;
    }
}