// Problem D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dr = {-1, -1, 1, 1};
vector<int> dc = {-1, 1, -1, 1};

void countTri(int a, int r, int c, int rr, int cc, vector<vector<vector<int>>>& dp, vector<string>& matrix){
    if(r + rr < 0 || r + rr >= matrix.size() || c + cc < 0 || c + cc >= matrix[0].size()){
        dp[a][r][c] = 1;
        return;
    }
    if(matrix[r][c] != matrix[r+rr][c] || matrix[r][c] != matrix[r][c+cc]){
        dp[a][r][c] = 1;
        return;
    }
    dp[a][r][c] = min(dp[a][r+rr][c], dp[a][r][c+cc]) + 1;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<string> matrix(N);
    for(int i = 0 ; i < N ; ++i){
        cin >> matrix[i];
    }
    vector<vector<vector<int>>> dp(4, vector<vector<int>>(N, vector<int>(M, -1)));

//    vector<vector<int>> leftup(N, vector<int>(M, -1));
//    vector<vector<int>> rightup(N, vector<int>(M, -1));
//    vector<vector<int>> leftdown(N, vector<int>(M, -1));
//    vector<vector<int>> rightdown(N, vector<int>(M, -1));
    
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < M ; ++j){
            countTri(0, i, j, dr[0], dc[0], dp, matrix);
        }
    }

    for(int i = 0 ; i < N ; ++i){
        for(int j = M-1 ; j >= 0 ; --j){
            countTri(1, i, j, dr[1], dc[1], dp, matrix);
        }
    }

    for(int i = N-1 ; i >= 0 ; --i){
        for(int j = 0 ; j < M ; ++j){
            countTri(2, i, j, dr[2], dc[2], dp, matrix);
        }
    }

    for(int i = N-1 ; i >= 0 ; --i){
        for(int j = M-1 ; j >= 0 ; --j){
            countTri(3, i, j, dr[3], dc[3], dp, matrix);
        }
    }


    ll ret = 0;
    for(int i = 0 ; i < N; ++i){
        for(int j = 0 ; j < M ; ++j){
            int tmp = 10000;
            for(int k = 0 ; k < 4 ; ++k){
                tmp = min(tmp, dp[k][i][j]);
            }
            ret += tmp;
        }
    }
    cout << ret << endl;

    return 0;
}