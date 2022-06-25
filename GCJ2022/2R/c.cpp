#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

lll getDist(vector<int>& a, vector<int>& b) {
    return (lll)(a[0] - b[0]) * (a[0] - b[0]) + (lll)(a[1] - b[1]) * (a[1] - b[1]);
}

bool compare(pair<lll, int>& a, pair<lll, int>& b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int N;
        cin >> N;
        vector<vector<int>> ch(N, vector<int>(2));
        for(int i = 0 ; i < N ; ++i) {
            cin >> ch[i][0] >> ch[i][1];
        }
        vector<vector<int>> sweet(N+1, vector<int>(2));

        for(int i = 0 ; i < N+1; ++i) {
            cin >> sweet[i][0] >> sweet[i][1];
        }
        
        vector<vector<pair<lll, int>>> dists(N, vector<pair<lll, int>>(N+1));
        vector<pair<int, int>> orders(N);
        for(int i = 0 ; i < N ; ++i) {
            for(int j = 0 ; j < N+1; ++j) {
                dists[i][j] = make_pair(getDist(ch[i], sweet[j]), j);
            }
            sort(dists[i].begin(), dists[i].end(), compare);
            int rank = upper_bound(dists[i].begin(), dists[i].end(), make_pair(getDist(ch[i], sweet[0]), N+10)) - dists[i].begin();
            orders[i] = make_pair(rank, i);
        }
        sort(orders.begin(), orders.end());
        unordered_set<int> used;
        bool isPossible = true;
        vector<vector<int>> ret(N);
        for(int i = 0 ; i < N ; ++i) {
            int c = orders[i].second;
            for(int j = 0 ; j < N+1 ; ++j) {
                if(dists[c][j].second == 0) {
                    isPossible = false;
                    break;
                }
                if(dists[c][j].second != 0 && used.find(dists[c][j].second) == used.end()) {
                    ret[i] = {c+1, dists[c][j].second + 1};
                    used.insert(dists[c][j].second);
                    break;
                }
            }
            if(!isPossible) {
                break;
            }
        }
        if(isPossible) {
            cout << "Case #" << t << ": " << "POSSIBLE" << endl;
            for(int i = 0 ; i < N ; ++i) {
                cout << ret[i][0] << ' ' << ret[i][1] << endl;
            }

        } else {
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;

        }
    }
    return 0;
}