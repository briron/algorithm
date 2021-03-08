// 1423. Maximum Points You Can Obtain from Cards
// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int subsum = 0;
        for(int i = 0 ; i < k ; ++i) {
            subsum += cardPoints[i];
        }
        int ret = subsum;
        int N = cardPoints.size();
        for(int i = k-1 ; i >= 0; --i) {
            subsum -= cardPoints[i];
            subsum += cardPoints[N-(k-i)];
            ret = max(ret, subsum);
        }
        return ret;
    }
};