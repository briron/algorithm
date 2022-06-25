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
        int N;
        cin >> N;
        string S;
        cin >> S;
        vector<int> rets = {1};
        char prev = S[0];
        for(int i = 1 ; i < S.size(); ++i) {
            if(prev < S[i]) {
                rets.push_back(rets.back() + 1);
            }
            else {
                rets.push_back(1);
            }
            prev = S[i];
        }

        cout << "Case #" << t << ":";
        for(int i = 0 ; i < rets.size() ; ++i) {
            cout << " " << rets[i];
        }
        cout << endl;
    }

    return 0;

}