// 721. Accounts Merge
// https://leetcode.com/problems/accounts-merge/

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) {
        parent = vector<int>(n);
        rank = vector<int>(n);
        for(int i = 0 ; i < n ; ++i){
            parent[i] = i;
        }
    }
    
    int add(int parent_index) {
        parent.push_back(parent_index);
        return parent.size() - 1;
    }
    
    int find(int a) {
        if(parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) {
            return;
        }
        if(rank[a] > rank[b]) {
            merge(b, a);
            return;
        }
        parent[a] = b;
        if(rank[a] == rank[b]) {
            rank[b] += 1;
        }
        return;
    }
    
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DisjointSet ds(accounts.size());
        unordered_map<string, int> email_hash;
        for(int i = 0 ; i < accounts.size(); ++i) {
            for(int j = 1 ; j < accounts[i].size(); ++j) {
                if(email_hash.find(accounts[i][j]) == email_hash.end()) {
                    email_hash[accounts[i][j]] = ds.add(i);
                }
                else {
                    ds.merge(i, email_hash[accounts[i][j]]);
                }
            }
        }
        
        unordered_map<int, int> name_index;
        vector<vector<string>> ret;
        for(int i = 0 ; i < accounts.size(); ++i) {
            if(ds.find(i) == i) {
                name_index[i] = name_index.size();
                ret.push_back({accounts[i][0]});
            }
        }
        
        for(auto it = email_hash.begin(); it != email_hash.end(); ++it) {
            ret[name_index[ds.find(it->second)]].push_back(it->first);
        }

        for(int i = 0 ; i < ret.size() ; ++i) {
            sort(ret[i].begin() + 1, ret[i].end());
        }
        
        return ret;
    }
};


/* make graph & dfs
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> graph;
        for(int i = 0 ; i < accounts.size() ; ++i) {
            for(int j = 1; j < accounts[i].size(); ++j) {
                if(j > 1) {
                    graph[accounts[i][j]].push_back(accounts[i][j-1]);
                    graph[accounts[i][j-1]].push_back(accounts[i][j]);
                }
            }
        }
        
        unordered_set<string> visited;
        vector<vector<string>> ret;
        for(int i = 0 ; i < accounts.size(); ++i) {
            if(visited.find(accounts[i][1]) != visited.end()) {
                continue;
            }
            ret.push_back({accounts[i][0]});
            dfs(accounts[i][1], graph, visited, ret);
        }
        
        for(int i = 0 ; i < ret.size(); ++i) {
            sort(ret[i].begin() + 1, ret[i].end());
        }
        
        return ret;
    }
    
    void dfs(string& email, unordered_map<string, vector<string>>& graph, unordered_set<string>& visited, vector<vector<string>>& ret) {
        visited.insert(email);
        ret.back().push_back(email);
        vector<string>& connected = graph[email];
        for(int i = 0 ; i < connected.size() ; ++i ){
            if(visited.find(connected[i]) == visited.end()) {
                dfs(connected[i], graph, visited, ret);            
            }
        }
        return;
    }
};
*/