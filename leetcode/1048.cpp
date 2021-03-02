// 1048. Longest String Chain
// https://leetcode.com/problems/longest-string-chain/

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size());
        unordered_map<int,vector<int>> len_words;
        for(int i = 0 ; i < words.size(); ++i) {
            len_words[words[i].size()].push_back(i);
        }
        int ret = 1;
        for(int i = 0 ; i < words.size(); ++i) {
            ret = max(ret, dfs(i, words, dp, len_words));
        }
        return ret;
    }
    
    bool isPred(string& pre, string& cur) {
        if(pre.size() + 1 != cur.size()) {
            return false;
        }
        int offset = 0;
        for(int i = 0; i < pre.size(); ++i) {
            if(pre[i] != cur[i+offset]) {
                offset += 1;
            }
            if(offset > 1) {
                return false;
            }
            if(pre[i] != cur[i+offset]) {
                return false;
            }
        }
        return true;
    }
    
    int dfs(int i, vector<string>& words, vector<int>& dp, unordered_map<int,vector<int>>& len_words) {
        if(dp[i] != 0) {
            return dp[i];
        }
        dp[i] = 1;
        for(int j : len_words[words[i].size() + 1]) {
            if(isPred(words[i], words[j])) {
                dp[i] = max(dp[i], 1+dfs(j, words, dp, len_words));
            }
        }
        return dp[i];
    }
    
};

/* sort + bottom-up DP + Trie
struct Trie {
    int chain;
    vector<Trie*> children;
    Trie() {
        chain = 0;
        children = vector<Trie*>(26, NULL);
    }
    void insert(string& s, int pos, int val) {
        if(pos == s.size() - 1) {
            chain = val;
            return;
        }
        int next = s[pos+1] - 'a';
        if(children[next] == NULL) {
            children[next] = new Trie();
        }
        children[next]->insert(s, pos+1, val);
    }
    int find(string& s, int pos, int offset) {
        if(pos == s.size() - 1) {
            if(offset == 0) {
                return 0;
            }
            return chain;
        }
        int ret = 0;
        if(offset == 0) {
            ret = max(ret, find(s, pos+1, offset+1));
        }
        int next = s[pos+1] - 'a';
        if(children[next] == NULL) {
            return ret;
        }
        return max(ret, children[next]->find(s, pos+1, offset));
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<int>> len_words(17);
        for(int i = 0 ; i < words.size(); ++i) {
            len_words[words[i].size()].push_back(i);
        }
        int ret = 0;
        Trie* trie = new Trie();
        for(int i = 0 ; i < len_words.size(); ++i) {
            for(int j = 0 ; j < len_words[i].size(); ++j) {
                int prev = trie->find(words[len_words[i][j]], -1, 0);
                ret = max(ret, prev+1);
                trie->insert(words[len_words[i][j]], -1, prev+1);
            }
        }
        return ret;
    }
        
};
*/