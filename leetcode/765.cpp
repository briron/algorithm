// 765. Couples Holding Hands
// https://leetcode.com/problems/couples-holding-hands/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> pos;
        for(int i = 0 ; i < row.size(); ++i) {
            pos[row[i]] = i;
        }
        int ret = 0;
        for(int i = 0 ; i < row.size() / 2 ; ++i) {
            if(row[i*2 + 1] == (row[i*2] ^ 1)) {
                continue;
            }
            ret += 1;
            swap(row[pos[row[i*2]^1]], row[i*2+1]);
            pos[row[pos[row[i*2]^1]]] = pos[row[i*2]^1];
        }
        return ret;
    }
};