// 695. Max Area of Island
// https://leetcode.com/problems/max-area-of-island/

// DFS
class Solution {
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        int answer = 0;
        for(int r = 0 ; r < grid.size() ; ++r) {
            for(int c = 0 ; c < grid[0].size() ; ++c) {
                if(grid[r][c] == 1) {
                    answer = max(answer, dfs(r, c, grid));
                }
            }
        }
        return answer;
    }
    
    int dfs(int r, int c, vector<vector<int>>& grid) {
        int answer = 1;
        grid[r][c] = 0;
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
                continue;
            }
            if(grid[nr][nc] == 1){
                answer += dfs(nr, nc, grid);
            }
        }
        return answer;
    }
};

/* Union-Find
struct DisjointSet {
    
    vector<int> parent;
    vector<int> rank;
    
    DisjointSet(vector<vector<int>>& grid) {
        parent = vector<int>(grid.size() * grid[0].size());
        rank = vector<int>(grid.size() * grid[0].size());
        for(int i = 0 ; i < grid.size() ; ++i){
            for(int j = 0 ; j < grid[0].size() ; ++j){
                int cur = i * grid[0].size() + j;
                if(grid[i][j] == 0){
                    parent[cur] = -1;
                }
                else{
                    parent[cur] = cur;
                    rank[cur] = 1;
                }
            }
        }
    }
    
    int find(int a) {
        if(parent[a] == -1 || parent[a] == a){
            return parent[a];
        }
        return parent[a] = find(parent[a]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == -1 || b == -1 || a == b){
            return;
        }
        if(rank[a] < rank[b]){
            merge(b, a);
            return;
        }
        parent[b] = a;
        rank[a] += rank[b];
        return;
    }
    
    int getSize(int a){
        int parent = find(a);
        if(parent == -1){
            return 0;
        }
        return rank[parent];
    }
};

class Solution {
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0){
            return 0;
        }
        DisjointSet ds(grid);
        int answer = 0;
        for(int r = 0 ; r < grid.size() ; ++r) {
            for(int c = 0 ; c < grid[0].size() ; ++c) {
                int cur = r * grid[0].size() + c;
                for(int i = 0 ; i < 4 ; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if(nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) {
                        continue;
                    }
                    int con = nr * grid[0].size() + nc;
                    ds.merge(cur, con);
                }
                answer = max(answer, ds.getSize(cur));
            }
        }
        return answer;
    }
};*/