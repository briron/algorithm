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