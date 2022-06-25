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
        string S;
        string F;
        cin >> S;
        cin >> F;
        vector<int> shortest(26, 26);
        for(int i = 0 ; i < 26 ; ++i) {
            for(int j = 0 ; j < F.size(); ++j) {
                int f = (F[j] - 'a');
                shortest[i] = min({shortest[i], (26 + (f - i)) % 26, (26 + (i - f)) % 26});
            }
        }
        int ret = 0;
        for(int i = 0 ; i < S.size() ; ++i) {
            ret += shortest[S[i] - 'a'];
        }

        cout << "Case #" << t << ": " << ret << endl;;
    }

    return 0;

}
