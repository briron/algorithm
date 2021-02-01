// 85. Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/

// stack
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        
        vector<int> subsum(matrix[0].size() + 1);
        
        int ret = 0;
        
        for(int r = 0 ; r < matrix.size() ; ++r) {
            deque<int> dq;
            dq.push_back(-1);
            for(int c = 0 ; c < subsum.size() ; ++c) {
                if(c == matrix[0].size() || matrix[r][c] == '0') {
                    subsum[c] = 0;
                }
                else {
                    subsum[c] += 1;
                }
                while(dq.back() != -1 && subsum[dq.back()] > subsum[c]) {
                    int col = dq.back();
                    dq.pop_back();
                    ret = max(ret, (c - dq.back() - 1) * subsum[col]);
                }
                dq.push_back(c);
            }
        }
        
        return ret;
        
    }
};

/* DP
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) {
            return 0;
        }
        vector<int> left(matrix[0].size());
        vector<int> right(matrix[0].size(), matrix[0].size());
        vector<int> height(matrix[0].size());
        int ret = 0;
        
        for(int r = 0 ; r < matrix.size() ; ++r) {
            int cur_left = 0;
            int cur_right = matrix[r].size();
            for(int c = 0 ; c < matrix[r].size() ; ++c) {
                if(matrix[r][c] == '0') {
                    height[c] = 0;
                }
                else {
                    height[c] += 1;
                }
            }
            
            for(int c = 0 ; c < matrix[r].size() ; ++c) {
                if(matrix[r][c] == '0') {
                    cur_left = c+1;
                    left[c] = 0;
                }
                else {
                    left[c] = max(left[c], cur_left);
                }
            }
            
            for(int c = matrix[r].size() - 1 ; c >= 0; --c) {
                if(matrix[r][c] == '0') {
                    cur_right = c;
                    right[c] = matrix[r].size();
                }
                else {
                    right[c] = min(right[c], cur_right);
                }
            }
            
            for(int c = 0 ; c < matrix[r].size() ; ++c) {
                ret = max(ret, height[c] * (right[c] - left[c]));
            }
        }
        
        return ret;
    }
};
*/