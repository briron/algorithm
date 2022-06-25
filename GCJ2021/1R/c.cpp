// g++ -std=c++17 c.cpp -o exe && ./exe && rm -rf exe

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 lll;


vector<int> dr = {0, 0, 1, -1};
vector<int> dc = {1, -1, 0, 0};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> matrix(R, vector<int>(C));

        for(int r = 0 ; r < R ; ++r) {
            for(int c = 0 ; c < C ; ++c) {
                cin >> matrix[r][c];
            }
        }

        ll ret = 0;

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}