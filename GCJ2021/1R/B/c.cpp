#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int getValidLo(vector<vector<ll>>& tower, int B) {
    int maxSize = 0;
    int maxLo = -1;
    int lo = -1;
    for(int i = 0 ; i < tower.size(); ++i) {
        if(tower[i].size() < B) {
            if(tower[i].size() == B-1 && lo != -1) {
                continue;
            }
            lo = i;
            if(tower[i].size() < B-1 && maxSize < tower[i].size()) {
                maxLo = i;
            }
        }
    }
    if(maxLo == -1) {
        return lo;
    }
    return maxLo;
}

int getValidHi(vector<vector<ll>>& tower, int B) {
    int maxSize = 0;
    int maxLo = -1;
    int lo = -1;
    for(int i = 0 ; i < tower.size(); ++i) {
        if(tower[i].size() == B-1) {
            return i;
        }
        if(tower[i].size() < B) {
            lo = i;
            if(tower[i].size() < B-1 && maxSize < tower[i].size()) {
                maxLo = i;
            }
        }
    }
    if(maxLo == -1) {
        return lo;
    }
    return maxLo;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T, N, B, P;
    cin >> T >> N >> B >> P;
    for(int t = 1 ; t <= T ; ++t) {
        vector<vector<ll>> tower(N);

        for(int i = 0 ; i < N * B ; ++i) {
            ll num;
            cin >> num;
            ll lo = 0;
            ll hi = 0;
            if(num < 8) {
                lo = getValidLo(tower, B);
                tower[lo].push_back(num);
                cout << lo + 1 << endl;
            } else {
                hi = getValidHi(tower, B);
                tower[hi].push_back(num);
                cout << hi + 1 << endl;
            }
        }
    }

    int verdict;
    cin >> verdict;

    return 0;

}