// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/

class Solution {
public:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char, vector<vector<int>>> start_points;
        int R = board.size();
        int C = board[0].size();
        for(int r = 0 ; r < R ; ++r) {
            for(int c = 0 ; c < C; ++c) {
                start_points[board[r][c]].push_back({r, c});
            }
        }
        vector<string> ret;
        vector<vector<bool>> visited(R, vector<bool>(C));
        
        for(string& word : words) {
            vector<vector<int>>& starts = start_points[word[0]];
            for(int i = 0 ; i < starts.size(); ++i) {
                if(dfs(word, 1, starts[i][0], starts[i][1], visited, board)) {
                    ret.push_back(word);
                    break;
                }
            }
        }
        return ret;
    }
    
    bool dfs(string& word, int pos, int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& board) {
        if(word.size() == pos) {
            return true;
        }
        visited[r][c] = true;
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(!inRange(nr, nc, visited)) {
                continue;
            }
            if(word[pos] == board[nr][nc]) {
                if(dfs(word, pos+1, nr, nc, visited, board)) {
                    visited[r][c] = false;
                    return true;
                }
            }
        }
        visited[r][c] = false;
        return false;
    }
    
    bool inRange(int r, int c, vector<vector<bool>>& visited) {
        if(r < 0 || r >= visited.size() || c < 0 || c >= visited[0].size()) {
            return false;
        }
        if(visited[r][c]) {
            return false;
        }
        return true;
    }
};