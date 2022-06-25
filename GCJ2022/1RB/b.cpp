#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        ll N, P;
        cin >> N >> P;

        vector<vector<ll>> arr(N, vector<ll>(P));

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < P ; ++j) {
                cin >> arr[i][j];
            }
        }

        vector<vector<ll>> dp(N, vector<ll>(2, LLONG_MAX/2));
        vector<vector<ll>> maxmins(N, vector<ll>(2, LLONG_MAX/2));

        for(int i = 0 ; i < N ; ++i) {
            maxmins[i][1] = 0;
        }

        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < P ; ++j) {
                maxmins[i][0] = min(maxmins[i][0], arr[i][j]);
                maxmins[i][1] = max(maxmins[i][1], arr[i][j]);
            }
        }

        dp[0][0] = 2 * maxmins[0][1] - maxmins[0][0];
        dp[0][1] = maxmins[0][1];

        for(int i = 1 ; i < N ; ++i) {
            for(int j = 0 ; j < P ; ++j) {
                dp[i][0] = min(dp[i-1][0] + abs(maxmins[i-1][0] - maxmins[i][1]), dp[i-1][1] + abs(maxmins[i-1][1] - maxmins[i][1])) + abs(maxmins[i][1] - maxmins[i][0]);
                dp[i][1] = min(dp[i-1][0] + abs(maxmins[i-1][0] - maxmins[i][0]), dp[i-1][1] + abs(maxmins[i-1][1] - maxmins[i][0])) + abs(maxmins[i][1] - maxmins[i][0]);
            }
        }

        cout << "Case #" << t << ": " << min(dp.back()[0], dp.back()[1]) << endl;
    }
    return 0;
}