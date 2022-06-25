#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

ll mod(ll one) {
    return (one + 1000000007) % (1000000007);
}

ll power(ll base, ll exp) {
    ll ret = 1;
    while(exp > 0) {
        if(exp % 2 == 0) {
            base *= base;
            base = mod(base);
            exp /= 2;
        } else {
            ret *= base;
            ret = mod(ret);
            exp -= 1;
        }
    }
    return ret;
}

ll inverse(ll one) {
    return power(one, 1000000005);
}

void buildParent(ll here, ll from, ll oo, ll no, vector<ll>& depth, vector<ll>& prob, vector<vector<vector<ll>>>& parent, vector<vector<vector<ll>>>& graph) {
    depth[here] = depth[from] + 1;
    prob[here] = mod(mod(prob[from] * oo) + mod(mod(1 - prob[from]) * no));
    parent[here][0] = {from, oo, no};
    for(int i = 1 ; i < parent[here].size() ; ++i) {
        ll anc = parent[here][i-1][0];
        if(anc == 0) {
            break;
        }
        parent[here][i][0] = parent[anc][i-1][0];
        parent[here][i][1] = mod( mod(parent[anc][i-1][1] * parent[here][i-1][1]) + mod( mod(1 - parent[anc][i-1][1]) * parent[here][i-1][2]));
        parent[here][i][2] = mod( mod(parent[anc][i-1][2] * parent[here][i-1][1]) + mod( mod(1 - parent[anc][i-1][2]) * parent[here][i-1][2]));
    }

    for(int i = 0 ; i < graph[here].size() ; ++i) {
        int there = graph[here][i][0];
        buildParent(there, here, graph[here][i][1], graph[here][i][2], depth, prob, parent, graph);
    }
}

ll findParent(ll one, ll other, vector<ll>& depth, vector<vector<vector<ll>>>& parent) {
    if(depth[one] < depth[other]) {
        return findParent(other, one, depth, parent);
    }
    for(int i = parent[one].size() - 1 ; i >= 0 ; --i) {
        if( (ll)1 << i <= depth[one] - depth[other]) {
            one = parent[one][i][0];
        }
    }
    if(one == other) {
        return one;
    }
    for(int i = parent[one].size() - 1 ; i >= 0 ; --i) {
        if(parent[one][i][0] != parent[other][i][0]) {
            one = parent[one][i][0];
            other = parent[other][i][0];
        }
    }
    return parent[one][0][0];
}

ll findProb(ll one, ll other, vector<ll>& depth, vector<ll>& prob, vector<vector<vector<ll>>>& parent) {
    ll lca = findParent(one, other, depth, parent);

    // {현재위치, 발생할 확률, 발생하지 않을 확률} = (최초에는) {one, 1, 0}
    // 다음부모가 발생할 때 발생할 확률 = 지금 부모가 발생할 때 발생할 확률 * 부모 사이에 발생할 때 발생할 확률
    // + 지금 부모가 발생하지 않을 때 발생할 확률 + 부모 사이에 발생할 때 발생하지 않을 확률 
    vector<ll> oneToLca = {one, 1, 0};

    for(int i = parent[one].size() - 1 ; i >= 0 ; --i) {
        if( (ll)1 << i <= depth[one] - depth[lca]) {
            ll next = parent[oneToLca[0]][i][0];
            ll nextoo = mod(mod(oneToLca[1] * parent[oneToLca[0]][i][1]) + mod(oneToLca[2] * mod(1 - parent[oneToLca[0]][i][1])));
            ll nextno = mod(mod(oneToLca[1] * parent[oneToLca[0]][i][2]) + mod(oneToLca[2] * mod(1 - parent[oneToLca[0]][i][2])));
            oneToLca = {next, nextoo, nextno};
            one = next;
        }
    }

    vector<ll> otherToLca = {other, 1, 0};

    for(int i = parent[other].size() - 1 ; i >= 0 ; --i) {
        if( (ll)1 << i <= depth[other] - depth[lca]) {
            ll next = parent[otherToLca[0]][i][0];
            ll nextoo = mod(mod(otherToLca[1] * parent[otherToLca[0]][i][1]) + mod(otherToLca[2] * mod(1 - parent[otherToLca[0]][i][1])));
            ll nextno = mod(mod(otherToLca[1] * parent[otherToLca[0]][i][2]) + mod(otherToLca[2] * mod(1 - parent[otherToLca[0]][i][2])));
            otherToLca = {next, nextoo, nextno};
            other = next;
        }
    }

    return mod(mod(mod(prob[lca] * oneToLca[1]) * otherToLca[1]) + mod(mod(mod(1-prob[lca]) * oneToLca[2]) * otherToLca[2]));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    ll P = 1e9 + 7;
    ll P_MAX = 1000000;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, Q;
        cin >> N >> Q;
        ll K;
        cin >> K;

        ll H = floor(log2(N)) + 1;
        vector<vector<vector<ll>>> graph(N+1);
        vector<vector<vector<ll>>> parent(N+1, vector<vector<ll>>(H, vector<ll>(3)));
        vector<ll> depth(N+1);
        vector<ll> prob(N+1);

        graph[0].push_back({1, mod(K * inverse(P_MAX)), 0});

        // 루트부터 DFS를 할 수 있도록 그래프를 만든다. (자식들만 저장하고 parent 를 저장하지 않는다) {자식노드idx, p, q}, 이때 p,q 는 mod(P * inverse(P_MAX)) 형태로 저장한다.
        // prob 는 독립확률
        // parent 는 lca 를 구하기 위한 parent 정보들이고, 이 때 {부모노드idx, p, q} 형태로 저장한다 p, q 는 부모가 실행될 때 실행될 확률, 실행되지 않을 때 실행될 확률이다
        // 쿼리에 대한 답은 두 점 a, b 에 대한 lca 인 l 을 구한 후에, l 의 독립 시행확률 * (l 이 실행될 때 a 가 실행될 확률) * (l 이 실행될 때 b 가 실행될 확률) + (1 - l의 확률) * (l이 실핼되지 않을 때 a 가 실핼될 확률) * (l이 실핼되지 않을 때 b 가 실핼될 확률) 로 구한다.
        // 두 확률의 곱은 그냥 곱한 후에 mod 값만 구하면 된다.

        prob[0] = 1;
        prob[1] = mod(K * inverse(P_MAX));
        
        for(int i = 0 ; i < N-1 ; ++i) {
            ll a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back({i+2, mod(b * inverse(P_MAX)), mod(c * inverse(P_MAX))});
        }

        buildParent(1, 0, mod(K * inverse(P_MAX)), 0, depth, prob, parent, graph);

        cout << "Case #" << t << ":";
        for(int i = 0 ; i < Q ; ++i) {
            ll a, b;
            cin >> a >> b;
            cout << " " << findProb(a, b, depth, prob, parent);
        }

        cout << endl;

    }

    return 0;

}