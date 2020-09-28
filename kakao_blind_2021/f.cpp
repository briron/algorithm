#include <bits/stdc++.h>

using namespace std;

vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};


vector<vector<int>> shift(vector<vector<int>>& board, int r, int c){
    vector<vector<int>> ret;
    for(int i = 0 ; i < 4 ; ++i){
        int next_r = r;
        int next_c = c;
        while(next_r + dr[i] >= 0 && next_r + dr[i] < 4 && next_c + dc[i] >= 0 && next_c + dc[i] < 4){
            next_r += dr[i];
            next_c += dc[i];
            if(board[next_r][next_c] != 0){
                break;
            }
        }
        ret.push_back({next_r, next_c});
    }
    return ret;
}

vector<int> bfs(vector<vector<int>>& board, int r, int c, int target){
    vector<vector<bool>> visited(4, vector<bool>(4));
    queue<vector<int>> q;
    q.push({r, c, 0});
    visited[r][c] = true;
    while(q.size() > 0){
        vector<int> here = q.front();
        cout << here[0] << ' ' << here[1] << ' ' << here[2] << endl;
        if(board[here[0]][here[1]] == target){
            return here;
        }
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int next_r = here[0] + dr[i];
            int next_c = here[1] + dc[i];
            if(next_r >= 0 && next_r < 4 && next_c >= 0 && next_c < 4){
                if(visited[next_r][next_c] == false){
                    q.push({next_r, next_c, here[2] + 1});
                    visited[next_r][next_c] = true;
                }
            }
        }
        vector<vector<int>> shifted = shift(board, r, c);
        for(int i = 0 ; i < shifted.size() ; ++i){
            cout << here[0] << ' ' << here[1] << ' '  << shifted[i][0] << ' ' << shifted[i][1] << endl;
            int next_r = shifted[i][0];
            int next_c = shifted[i][1];
            if(visited[next_r][next_c] == false){
                q.push({next_r, next_c, here[2] + 1});
                visited[next_r][next_c] = true;
            }
        }
    }
    return {0, 0, 0};
}


void permutation(vector<vector<int>>& board, int r, int c, int& ret, vector<int>& v, vector<int>& seq, vector<bool>& inserted){
    if(seq.size() == v.size()){
        // bfs
        int count = 0;
        vector<vector<int>> board_tmp;
        board_tmp.assign(board.begin(), board.end());
        for(int i = 0 ; i < seq.size(); ++i){
            for(int j = 0 ; j < 2; ++j){
                vector<int> here = bfs(board_tmp, r, c, seq[i]);
                board_tmp[here[0]][here[1]] = 0;
                count += here[2];
                cout << seq[i] << endl;
                r = here[0];
                c = here[1];
                cout << count << endl;
                cout << endl;
            }
        }
        cout << count << endl;
        ret = min(ret, count);
    }
    for(int i = 0 ; i < v.size() ; ++i){
        if(inserted[i] == false){
            seq.push_back(v[i]);
            inserted[i] = true;
            permutation(board, r, c, ret, v, seq, inserted);
            inserted[i] = false;
            seq.pop_back();
        }
    }
    return;
}


int solution(vector<vector<int>> board, int r, int c) {
    set<int> s;
    for(int i = 0 ; i < board.size() ; ++i){
        for(int j = 0 ; j < board[0].size(); ++j){
            s.insert(board[i][j]);
        }
    }
    vector<int> v;
    for(auto it = s.begin(); it != s.end() ; ++it){
        if(*it != 0){
            v.push_back(*it);
        }
    }
    vector<bool> inserted(v.size());
    vector<int> seq;
    int ret = INT_MAX;
    permutation(board, r, c, ret, v, seq, inserted);

    ret += ((int)v.size()) * 2; 
    return ret;
}