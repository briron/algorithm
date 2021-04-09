#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> dr = {0, 0, 1, -1};
vector<int> dc = {1, -1, 0, 0};

int traverse(vector<int>& here, vector<vector<int>>& matrix, priority_queue<vector<int>>& pq) {
    int ret = 0;
    for(int i = 0 ; i < 4 ; ++i) {
        int nr = here[1] + dr[i];
        int nc = here[2] + dc[i];
        if(nr < 0 || nr >= matrix.size() || nc < 0 || nc >= matrix[0].size()) {
            continue;
        }
        if(here[0] - 1 <= matrix[nr][nc]) {
            continue;
        }
        ret += (here[0] - 1) - matrix[nr][nc];
        matrix[nr][nc] = here[0] - 1;
        pq.push({matrix[nr][nc], nr, nc});
    }
    return ret;
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
        priority_queue<vector<int>> pq;

        for(int i = 0 ; i < R ; ++i) {
            for(int j = 0 ; j < C ; ++j) {
                cin >> matrix[i][j];
                pq.push({matrix[i][j], i, j});
            }
        }

        ll ret = 0;

        while(!pq.empty()) {
            vector<int> here = pq.top();
            pq.pop();
            ret += traverse(here, matrix, pq);
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;

}