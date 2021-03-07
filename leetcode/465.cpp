// 465. Optimal Account Balancing
// https://leetcode.com/problems/optimal-account-balancing/

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for(int i = 0 ; i < transactions.size() ; ++i) {
            balance[transactions[i][0]] += transactions[i][2];
            balance[transactions[i][1]] -= transactions[i][2];            
        }
        vector<int> plus;
        vector<int> minus;
        for(auto it = balance.begin(); it != balance.end(); ++it) {
            if(it->second > 0) {
                plus.push_back(it->second);
            }
            else if(it->second < 0) {
                minus.push_back(it->second);
            }
        }
        
        return dfs(0, 0, plus, minus);
    }
    
    int dfs(int p_index, int m_index, vector<int>& plus, vector<int>& minus) {
        if(p_index >= plus.size()) {
            return 0;
        }
        if(plus[p_index] == 0) {
            return dfs(p_index+1, 0, plus, minus);
        }
        while(m_index < minus.size() && minus[m_index] == 0) {
            m_index += 1;
        }
        if(m_index == minus.size()) {
            return INT_MAX/2;
        }        
        
        int unused = dfs(p_index, m_index+1, plus, minus);
        int used = INT_MAX/2;

        if(plus[p_index] + minus[m_index] <= 0) {
            int tmp = plus[p_index];
            plus[p_index] = 0;
            minus[m_index] += tmp;
            used = 1 + dfs(p_index+1, 0, plus, minus);
            plus[p_index] = tmp;
            minus[m_index] -= tmp;            
        }
        else {
            int tmp = minus[m_index];
            plus[p_index] += tmp;
            minus[m_index] = 0;
            used = 1 + dfs(p_index, m_index+1, plus, minus);
            plus[p_index] -= tmp;
            minus[m_index] = tmp;
        }
        
        return min(unused, used);            
    }
};