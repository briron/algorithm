// g++ -std=c++17 b.cpp -o exe && ./exe && rm -rf exe

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll divide(ll s, unordered_map<ll,ll>& primes) {
    ll pSum = 0;
    for(auto it = primes.begin(); it != primes.end() ; ++it) {
        ll lower = min((ll)60, it->second);
        for(int i = 0 ; i < lower ; ++i) {
            if(s % it->first != 0) {
                break;
            }
            s /= it->first;
            pSum += it->first;
            if(s == 1) {
                return pSum;
            }
        }
    }
    return -1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int M;
        cin >> M;
        unordered_map<ll, ll> primes;
        ll S = 0;
        for(int i = 0 ; i < M ; ++i) {
            ll P, N;
            cin >> P >> N;
            primes[P] = N;
            S += N * P;
        }

        ll ret = 0;

        ll lower = max((ll)2, S - 30000);

        for(ll s = S; s >= lower; --s) {
            ll pSum = divide(s, primes);
            if(pSum != -1 && pSum + s == S) {
                ret = s;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << ret << endl;

    }

    return 0;

}