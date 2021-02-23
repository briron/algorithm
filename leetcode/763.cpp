// 763. Partition Labels
// https://leetcode.com/problems/partition-labels/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> last_indices;
        for(int i = 0 ; i < S.size() ; ++i) {
            last_indices[S[i]] = i;
        }
        vector<int> ret;
        int max_index = 0;
        int prev = -1;
        for(int i = 0 ; i < S.size() ; ++i) {
            max_index = max(max_index, last_indices[S[i]]);
            if(i == max_index) {
                ret.push_back(i - prev);
                prev = i;
            }
        }
        return ret;
    }
};