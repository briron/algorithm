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
        int R, C, F, S;
        cin >> R >> C >> F >> S;
        vector<string> source;
        vector<string> target;
        for(int i = 0 ; i < R ; ++i) {
            string a;
            cin >> a;
            source.push_back(a);
        }
        for(int i = 0 ; i < R ; ++i) {
            string a;
            cin >> a;
            target.push_back(a);
        }

        ll ret = 0;
        


        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}