// 84. Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        vector<int> st;
        st.push_back(-1);
        for(int i = 0 ; i < heights.size() ; ++i) {
            while(st.back() != -1 && heights[st.back()] > heights[i]) {
                int h = heights[st.back()];
                st.pop_back();
                ret = max(ret, h * (i - st.back() - 1));
            }
            st.push_back(i);
        }
        while(st.back() != -1) {
            int h = heights[st.back()];
            st.pop_back();
            ret = max(ret, h * ((int)heights.size() - st.back() - 1));
        }
        return ret;
    }
};
