// 1081. Smallest Subsequence of Distinct Characters
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> lastPos;
        for(int i = 0 ; i < s.size() ; ++i) {
            lastPos[s[i]] = i;
        }
        string ret;
        unordered_set<char> used;
        for(int i = 0; i < s.size() ; ++i) {
            if(used.find(s[i]) != used.end()) {
                continue;
            }
            while(ret.size() > 0 && lastPos[ret.back()] > i && ret.back() > s[i]) {
                used.erase(ret.back());
                ret.pop_back();
            }
            ret.push_back(s[i]);
            used.insert(s[i]);
        }
        return ret;
    }
};