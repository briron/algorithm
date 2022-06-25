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
        ll N, K, S;
        cin >> N >> K >> S;
        cout << "Case #" << t << ": " << min(N+K, N+2*K-2*S) << endl;
    }

    return 0;

}