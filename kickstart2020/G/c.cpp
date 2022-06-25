#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll W, N;
        cin >> W >> N;
        vector<ll> arr(W);
        for(int i = 0; i < W; ++i) {
            cin >> arr[i];
            arr[i] *= 2;
        }
        ll lo = 0;
        ll ret = 0;
        ll counter = arr[lo] + arr.size();
        ll hi = upper_bound(arr.begin(), arr.end(), counter) - arr.begin();
        ll minus = hi - 1;
        ll plus = arr.size() - minus;
        for(int i = 0 ; i < arr.size() ; ++i) {
            ret += min ( (N + (arr[i] - arr[0])) % N , (N + (arr[0] - arr[i])) % N);
        }



        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}