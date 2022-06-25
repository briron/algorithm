#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, N;
    cin >> T >> N;
    for(int t = 1 ; t <= T ; ++t) {
        for(int i = 1 ; i <= N-1 ; ++i) {
            cout << "M " << i << ' ' << N << endl;
            int pos;
            cin >> pos;
            if(i == pos) {
                continue;
            }
            cout << "S " << i << ' ' << pos << endl;
            int judge;
            cin >> judge;
        }
        cout << "D" << endl;
        int ret;
        cin >> ret;
    }

    return 0;

}