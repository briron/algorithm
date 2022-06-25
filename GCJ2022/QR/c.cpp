#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<int> dice(N);
        for(int i = 0 ; i < N ; ++i) {
            cin >> dice[i];
        }
        sort(dice.begin(), dice.end());
        int ret = 0;
        for(int i = 0 ; i < dice.size() ; ++i) {
            if(ret + 1 <= dice[i]) {
                ++ret;
            }
        }

        cout << "Case #" << t << ": " << ret << endl;
    }
}