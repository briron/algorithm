#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int getCount(int one, int other) {
    return max(0, min(one, other/2) - 1) + max(0, min(one/2, other) - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; ++t) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> matrix(R, vector<int>(C));
        for(int i = 0 ; i < R ; ++i) {
            for(int j = 0 ; j < C ; ++j) {
                cin >> matrix[i][j];
            }
        }

        ll ret = 0;
        
        vector<vector<vector<int>>> updown(R, vector<vector<int>>(C, vector<int>(2)));
        vector<vector<vector<int>>> leftright(R, vector<vector<int>>(C, vector<int>(2)));

        for(int r = 0 ; r < R; ++r) {
            for(int c = 0 ; c < C; ++c) {
                if(r == 0) {
                    updown[r][c][0] = matrix[r][c];
                    continue;
                }
                if(matrix[r][c] == 0) {
                    updown[r][c][0] = 0;
                }
                else {
                    updown[r][c][0] = updown[r-1][c][0] + 1;
                }
            }
        }


        for(int r = R-1 ; r >= 0; --r) {
            for(int c = 0 ; c < C; ++c) {
                if(r == R-1) {
                    updown[r][c][1] = matrix[r][c];
                    continue;
                }
                if(matrix[r][c] == 0) {
                    updown[r][c][1] = 0;
                }
                else {
                    updown[r][c][1] = updown[r+1][c][1] + 1;
                }
            }
        }


        for(int r = 0 ; r < R; ++r) {
            for(int c = 0 ; c < C; ++c) {
                if(c == 0) {
                    leftright[r][c][0] = matrix[r][c];
                    continue;
                }
                if(matrix[r][c] == 0) {
                    leftright[r][c][0] = 0;
                }
                else {
                    leftright[r][c][0] = leftright[r][c-1][0] + 1;
                }
            }
        }


        for(int r = 0 ; r < R; ++r) {
            for(int c = C-1 ; c >= 0; --c) {
                if(c == C-1) {
                    leftright[r][c][1] = matrix[r][c];
                    continue;
                }
                if(matrix[r][c] == 0) {
                    leftright[r][c][1] = 0;
                }
                else {
                    leftright[r][c][1] = leftright[r][c+1][1] + 1;
                }
            }
        }

        for(int r = 0 ; r < R; ++r) {
            for(int c = 0 ; c < C ; ++c) {
                if(matrix[r][c] != 0) {
                    ret += getCount(updown[r][c][0], leftright[r][c][0]);
                    ret += getCount(updown[r][c][0], leftright[r][c][1]);
                    ret += getCount(updown[r][c][1], leftright[r][c][0]);
                    ret += getCount(updown[r][c][1], leftright[r][c][1]);
                }
            }
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}