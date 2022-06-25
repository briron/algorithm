#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;

    std::random_device rd;

    std::mt19937 gen(rd());

    
    for(int t = 1 ; t <= T ; ++t) {
        ll N, K;
        cin >> N >> K;
        ll S, SR;
        cin >> S >> SR;
        if(N <= K) {
            ll sum = 0;
            for(ll i = 1 ; i <= N ; ++i) {
                cout << "T " << i << endl;
                ll R, P;
                cin >> R >> P;
                sum += P;
            }
            cout << "E " << sum / 2 << endl;
        } else {
            std::uniform_int_distribution<int> dis(1, N);
            ll sum = SR;
            for(ll i = 1 ; i <= K ; ++i) {
                cout << "T " << dis(gen) << endl;
                ll R, P;
                cin >> R >> P;
                sum += P;
            }
            ll ret = round((N * sum) / (2 * (K+1)));
            cout << "E " << ret << endl;
        }
    }
}