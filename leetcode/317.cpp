// 317. Shortest Distance from All Buildings
// https://leetcode.com/problems/shortest-distance-from-all-buildings/submissions/

class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    
    int shortestDistance(vector<vector<int>>& grid) {
        int R = grid.size();
        if(R == 0) {
            return -1;
        }
        int C = grid[0].size();
        vector<vector<pair<int,int>>> visited(R, vector<pair<int,int>>(C));
        int idx = 1;
        for(int r = 0 ; r < R ; ++r) {
            for(int c = 0 ; c < C ; ++c) {
                if(grid[r][c] == 1) {
                    queue<vector<int>> q;
                    q.push({r, c, 0});
                    bfs(q, idx, grid, visited);
                    idx += 1;
                }
            }
        }
        int ret = INT_MAX;
        for(int r = 0 ; r < R ; ++r) {
            for(int c = 0 ; c < C ; ++c) {
                if(grid[r][c] == 0 && visited[r][c].first == idx-1) {
                    ret = min(ret, visited[r][c].second);
                }
            }
        }
        if(ret == INT_MAX) {
            return -1;
        }
        return ret;
    }
    
    void bfs(queue<vector<int>>& q, int idx, const vector<vector<int>>& grid, vector<vector<pair<int,int>>>& visited) {
        while(q.size() > 0) {
            int r = q.front()[0];
            int c = q.front()[1];
            int dist = q.front()[2];
            q.pop();
            
            for(int i = 0 ; i < 4 ; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(inRange(nr, nc, idx, grid, visited)) {
                    visited[nr][nc].first = idx;
                    visited[nr][nc].second += dist + 1;
                    q.push({nr, nc, dist+1});
                }
            }
        }
    }
    
    bool inRange(int r, int c, int idx, const vector<vector<int>>& grid, vector<vector<pair<int,int>>>& visited) {
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return false;
        }
        if(visited[r][c].first != idx-1) {
            return false;
        }
        if(grid[r][c] != 0) {
            return false;
        }
        return true;
    }
};

