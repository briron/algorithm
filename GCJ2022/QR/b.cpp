#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;

int main() {
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        vector<vector<int>> printers(3, vector<int>(4));
        for(int i = 0 ; i < 3 ; ++i) {
            for(int j = 0 ; j < 4; ++j){
                cin >> printers[i][j];
            }
        }
        vector<int> ret(4);
        for(int i = 0 ; i < 4 ; ++i){
            ret[i] = min({printers[0][i], printers[1][i], printers[2][i]});
        }

        int acc = 0;

        for(int i = 0 ; i < 4 ; ++i) {
            ret[i] = min(1000000-acc, ret[i]);
            acc += ret[i];
        }
        cout << "Case #" << t << ": ";

        if(acc != 1000000) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for(int i = 0 ; i < 4 ; ++i) {
                cout << ret[i] << " ";
            }
            cout << endl;
        }
    }
}