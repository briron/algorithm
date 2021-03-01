// 329. Longest Increasing Path in a Matrix
// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ret = 0;
        vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int r = 0 ; r < matrix.size(); ++r) {
            for(int c = 0 ; c < matrix[r].size(); ++c) {
                ret = max(ret, dfs(r, c, matrix, visited));
            }
        }
        return ret;
    }
    
    int dfs(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& visited) {
        if(visited[r][c] != -1) {
            return visited[r][c];
        }
        visited[r][c] = 1;
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!inRange(nr, nc, visited)) {
                continue;
            }
            if(matrix[r][c] < matrix[nr][nc]) {
                visited[r][c] = max(visited[r][c], 1 + dfs(nr, nc, matrix, visited));
            }
        }
        return visited[r][c];
    }
    
    bool inRange(int r, int c, vector<vector<int>>& visited) {
        if(r < 0 || r >= visited.size() || c < 0 || c >= visited[r].size()) {
            return false;
        }
        return true;
    }
};