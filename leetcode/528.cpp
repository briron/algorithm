// 528. Random Pick with Weight
// https://leetcode.com/problems/random-pick-with-weight/

class Solution {
public:
    mt19937 gen;
    uniform_int_distribution<int> dis;
    vector<int> subsum;

    Solution(vector<int>& w) {
        gen = mt19937(19937);
        for(int i = 0 ; i < w.size(); ++i){
            sum += w[i];
            subsum.push_back(sum);
        }
        dis = uniform_int_distribution<int>(1, sum);
    }
    
    int pickIndex() {
        int random = dis(gen);
        upper_bound()
        return it->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */