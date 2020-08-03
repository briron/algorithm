#include <bits/stdc++.h>
using namespace std;

bool dfs(int start, vector<int>& match, vector<bool>& v, vector<vector<int>>& g){
    if(v[start]){
        return false;
    }
    v[start] = true;
    for(int i = 0 ; i < g[start].size(); ++i){
        if(match[g[i]] == -1 || dfs(match[g[i]])){
            match[start] = g[i];
            match[g[i]] = start;
            return true;
        }
    }
    return false;
}

int bipartiteMatch(vector<vector<int>>& g, vector<int>& a){
    vector<int> match(g.size(), -1);
    int ret = 0;
    for(int start = 0 ; start < a.size(); ++start){
        v = vector<bool>(a.size());
        if(dfs(start, match, v, g)){
            ++ret;
        }
    }
    return ret;
}
