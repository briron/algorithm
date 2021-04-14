#include <bits/stdc++.h>
using namespace std;

bool dfs(int here, vector<int>& match, vector<bool>& v, vector<vector<int>>& g){
    if(v[here]){
        return false;
    }
    v[here] = true;
    for(int i = 0 ; i < g[here].size(); ++i){
        int there = g[here][i];
        if(match[there] == -1 || dfs(there, match, v, g) ) {
            match[here] = there;
            match[there] = here;
            return true;
        }
    }
    return false;
}

int bipartiteMatch(vector<vector<int>>& g, vector<int>& a){
    vector<int> match(g.size(), -1);
    int ret = 0;
    for(int start = 0 ; start < a.size(); ++start){
        vector<bool> v = vector<bool>(a.size());
        if(dfs(start, match, v, g)){
            ++ret;
        }
    }
    return ret;
}
