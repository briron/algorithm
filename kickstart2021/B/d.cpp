#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll gcd(ll a, ll b) {
    if(a < 0 || b < 0) {
        return 0;
    }
    if(b > a) {
        return gcd(b, a);
    }
    if(b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

class Segment {
    vector<ll> tree = vector<ll>(4*200000, 0L);
    ll n = tree.size();
    public:
        Segment() {

        }
        ll query(ll weight) {
            return query(1, 0, n-1, 0, weight);
        }
        ll query(ll nodeIndex, ll nodeLeft, ll nodeRight, ll arrLeft, ll arrRight) {
            if(arrRight < nodeLeft || nodeRight < arrLeft) {
                return 0;
            }
            if(arrLeft <= nodeLeft && nodeRight <= arrRight) {
                return tree[nodeIndex];
            }
            ll mid = (nodeLeft + nodeRight) / 2;
            ll left = query(nodeIndex*2, nodeLeft, mid, arrLeft, arrRight);
            ll right = query(nodeIndex*2+1, mid+1, nodeRight, arrLeft, arrRight);
            return gcd(left, right);
        }
        void update(ll idx, ll val) {
            update(1, 0, n-1, idx, val);
        }
        ll update(ll nodeIndex, ll nodeLeft, ll nodeRight, ll idx, ll val) {
            if(idx < nodeLeft || nodeRight < idx) {
                return tree[nodeIndex];
            }
            if(nodeLeft == nodeRight && nodeLeft == idx) {
                return tree[nodeIndex] = val;
            }
            ll mid = (nodeLeft + nodeRight) / 2;
            ll left = update(nodeIndex*2, nodeLeft, mid, idx, val);
            ll right = update(nodeIndex*2+1, mid+1, nodeRight, idx, val);
            return tree[nodeIndex] = gcd(left, right);
        }
};

void dfs(ll here, ll before, Segment& sg, vector<vector<vector<ll>>>& graph, vector<vector<vector<ll>>>& queries, vector<ll>& rets) {

    for(auto& q : queries[here]) {
        ll id = q[0];
        ll weight = q[1];
        rets[id] = sg.query(weight);
    }

    for(ll i = 0; i < graph[here].size() ; ++i) {
        if(graph[here][i][0] == before) {
            continue;
        }

        ll there = graph[here][i][0];
        ll limit = graph[here][i][1];
        ll toll = graph[here][i][2];
        sg.update(limit, toll);
        dfs(there, here, sg, graph, queries, rets);
        sg.update(limit, 0);
    }

    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, Q;
        cin >> N >> Q;
        vector<vector<vector<ll>>> graph(N+1);
        for(ll i = 0 ; i < N-1 ; ++i) {
            ll x, y, l, a;
            cin >> x >> y >> l >> a;
            graph[x].push_back({y, l, a});
            graph[y].push_back({x, l, a});
        }

        vector<vector<vector<ll>>> queries(N+1);
        vector<ll> rets(Q);

        for(ll i = 0 ; i < Q ; ++i) {
            ll city, weight;
            cin >> city >> weight;
            queries[city].push_back({i, weight});
        }

        Segment sg;

        dfs(1, 1, sg, graph, queries, rets);

        cout << "Case #" << t << ":";
        for(ll i = 0 ; i < Q ; ++i) {
            cout << ' ' << rets[i];
        }
        cout << endl;
    }

    return 0;

}