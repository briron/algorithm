#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int X;
        int Y;
        string mural;
        cin >> X >> Y >> mural;
        vector< vector<int> > dp(mural.size(), vector<int>(2, INT_MAX / 2));
        if(mural[0] == 'C') {
            dp[0][0] = 0;
        }
        else if(mural[0] == 'J') {
            dp[0][1] = 0;
        }
        else {
            dp[0][0] = 0;
            dp[0][1] = 0;
        }
        for(int i = 1 ; i < mural.size() ; ++i) {
            if(mural[i] == 'C') {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
            }
            else if(mural[i] == 'J') {
                dp[i][1] = min(dp[i-1][0] + X, dp[i-1][1]);
            }
            else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + Y);
                dp[i][1] = min(dp[i-1][0] + X, dp[i-1][1]);
            }
        }
        
        int ret = min(dp.back()[0], dp.back()[1]);

        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}
