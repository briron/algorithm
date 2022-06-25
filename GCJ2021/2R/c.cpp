#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

vector<ll> inv(100001);
vector<ll> fact(100001);
vector<ll> fact_inv(100001);


ll P = 1e9+7;

ll combi(ll n, ll r) {
    if(n == r || r == 0) {
        return 1;
    }
    return (fact[n] * fact_inv[n-r] % P) * fact_inv[r] % P;
}

ll getPancakes(ll base, ll start, ll last, vector<ll>& arr, vector<vector<ll>>& pos) {
    if(start > last) {
        return 1;
    }
    if(start == last) {
        if(arr[start] == base) {
            return 1;
        } else {
            return 0;
        }
    }
    auto it = upper_bound(pos[base].begin(), pos[base].end(), last);
    if(it != pos[base].begin() && *prev(it) >= start) {
        ll idx = *prev(it);
        ll ret = (getPancakes(base + 1, idx + 1, last, arr, pos) * getPancakes(base, start, idx - 1, arr, pos)) % P;
        ret *= combi(last - start, (idx - start));
        ret %= P;
        return ret;
    }
    return 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    inv[1] = 1;
    for(int i=2; i<100001; i++){
        inv[i] = P - (P/i) * inv[P%i] % P;
    }
    fact[0] = 1; 
    fact_inv[0] = 1; 
    for(int i=1; i<100001; i++){
        fact[i] = fact[i-1]*i % P;
        fact_inv[i] = fact_inv[i-1]*inv[i] % P;
    }


    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N;
        cin >> N;
        vector<ll> arr(N);
        vector<vector<ll>> pos(N+1);
        for(int i = 0 ; i < N ; ++i) {
            cin >> arr[i];
            pos[arr[i]].push_back(i);
        }
        ll ret = getPancakes(1, 0, N-1, arr, pos);


        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}