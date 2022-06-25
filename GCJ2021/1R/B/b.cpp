#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


bool isValid(ll val, vector<ll>& arr) {
    int here = 1;
    int there = 0;
    for(ll i = val ; i >= 1 ; --i) {
        if(arr.size() <= i) {
            ll tmp = here;
            here += there;
            there = tmp;
        }
        else if(arr[i] > here) {
            return false;
        }
        else {
            here -= arr[i];
            ll tmp = here;
            here += there;
            there = tmp;            
        }
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, A, B;
        cin >> N >> A >> B;
        vector<ll> arr(N+1);
        for(int i = 1 ; i < N+1; ++i) {
            cin >> arr[i];
        }

        ll ret = 100;
        for(ll i = 40 ; i >= 1 ; --i) {
            if(isValid(i, arr)) {
                ret = i;
            }
            if(i <= N) {
                break;
            }
        }
        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}