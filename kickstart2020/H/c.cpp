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
        ll N;
        cin >> N;

        vector<vector<ll>> points(N, vector<ll>(2));
        vector<ll> ygroup(N);
        vector<ll> xgroup(N);

        for(int i = 0; i < N ; ++i) {
            cin >> points[i][0] >> points[i][1]; 
            xgroup[i] = points[i][0];
            ygroup[i] = points[i][1];
        }

        sort(xgroup.begin(), xgroup.end());
        sort(ygroup.begin(), ygroup.end());

        vector<ll> xgroup2(N);

        for(int i = 0 ; i < xgroup.size() ; ++i) {
            xgroup2[i] = xgroup[i] - i;
        }

        sort(xgroup2.begin(), xgroup2.end());

        ll y = ygroup[N/2];
        ll x = xgroup2[N/2];

        ll ret = 0;

        for(int i = 0 ; i < points.size() ; ++i) {
            ret += abs(x + i - xgroup[i]) + abs(ygroup[i] - y);
        }


        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}