#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


vector<vector<ll>> shorten(vector<vector<ll>>& arr) {
    vector<vector<ll>> ret;
    sort(arr.begin(), arr.end());
    for(int i = 0 ; i < arr.size() ; ++i) {
        while(!ret.empty() && ret.back().back() >= arr[i].back()) {
            ret.pop_back();
        }
        if(ret.empty() || ret.back().front() < arr[i].front()) {
            ret.push_back(arr[i]);
        }
    }
    return ret;
}

struct Segment {
    ll n;
    vector<ll> tree;
    Segment(vector<ll>& arr) {
        n = arr.size();
        tree = vector<ll>(4*n);
        init(1, 0, arr.size()-1, arr);
    }

    ll init(ll nodeIdx, ll arrLeft, ll arrRight, vector<ll>& arr) {
        if (arrLeft == arrRight) {
            return tree[nodeIdx] = arr[arrLeft];
        }
        ll mid = (arrLeft + arrRight) / 2;
        ll left = init(2 * nodeIdx, arrLeft, mid, arr);
        ll right = init(2 * nodeIdx + 1, mid+1, arrRight, arr);
        return tree[nodeIdx] = min(left, right);
    }

    ll query(ll arrLeft, ll arrRight) {
        if(arrRight < arrLeft) {
            return LLONG_MAX / 2;
        }
        return query(1, 0, n-1, arrLeft, arrRight);
    }

    ll query(ll nodeIdx, ll nodeLeft, ll nodeRight, ll arrLeft, ll arrRight) {
        if(nodeRight < arrLeft || arrRight < nodeLeft) {
            return LLONG_MAX / 2;
        }
        if(arrLeft <= nodeLeft && nodeRight <= arrRight) {
            return tree[nodeIdx];
        }
        ll mid = (nodeLeft + nodeRight) / 2;
        ll left = query(2 * nodeIdx, nodeLeft, mid, arrLeft, arrRight);
        ll right = query(2 * nodeIdx + 1, mid + 1, nodeRight, arrLeft, arrRight);
        return min(left, right);
    }

};

Segment make_tree(vector<vector<ll>>& arr) {
    vector<ll> tree(arr.size());
    for(int i = 0 ; i < arr.size() ; ++i) {
        tree[i] = arr[i].back() - arr[i].front() + 1;
    }
    return Segment(tree);
}

bool cmp(vector<ll>& a, vector<ll>& b) {
    if(a.back() == b.back()) {
        return a.front() < b.front();
    }
    return a.back() < b.back();
}

ll find_smallest(ll start, ll end, vector<vector<ll>>& arr, Segment& tree) {
    ll left = upper_bound(arr.begin(), arr.end(), vector<ll>({start, start}), cmp) - arr.begin();
    left -= 1;
    ll right = upper_bound(arr.begin(), arr.end(), vector<ll>{end, LLONG_MAX}) - arr.begin();
    return min(tree.query(0, left), tree.query(right, (ll)arr.size() - 1));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, K;
        cin >> N >> K;
        vector<ll> bananas(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> bananas[i];
        }

        vector<ll> subsum(N+1);
        for(int i = 1 ; i < N+1 ; ++i) {
            subsum[i] = subsum[i-1] + bananas[i-1];
        }

        unordered_map<ll, vector<vector<ll>>> hash;
        unordered_map<ll, Segment> tree;

        for(int i = 0 ; i < N ; ++i) {
            for(int j = i+1 ; j < N+1 ; ++j) {
                hash[subsum[j] - subsum[i]].push_back({i, j-1});
            }
        }

        for(auto it = hash.begin() ; it != hash.end() ; ++it) {
            it->second = shorten(it->second);
            tree[it->first] = make_tree(it->second);
        }

        ll ret = N+1;

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 1 ; j < N+1 ; ++j) {
                ll target = K - (subsum[j] - subsum[i]);
                if(target < 0) {
                    continue;
                }
                if(target == 0) {
                    ret = min(ret, (ll)(j-i));
                }
                ret = min(ret, (ll)(j-i) + find_smallest(i, j-1, hash[target], tree[target]));
            }
        }

        if(ret == N+1) {
            ret = -1;
        }


        cout << "Case #" << t << ": " << ret << endl;;
    }

    return 0;

}
