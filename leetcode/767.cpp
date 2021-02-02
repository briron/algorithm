// 767. Reorganize String
// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> char_count;
        for(int i = 0 ; i < S.size() ; ++i){
            char_count[S[i]] += 1;
        }
        int maxCount = 0;
        char maxChar = 'a';
        for(auto it = char_count.begin(); it != char_count.end(); ++it){
            if(it->second > maxCount){
                maxChar = it->first;
                maxCount = it->second;
            }
        }
        if(maxCount > (S.size() + 1) / 2) {
            return "";
        }
        string ret(S.size(), ' ');
        int pos = 0;
        for(int i = 0 ; i < maxCount ; ++i){
            ret[pos] = maxChar;
            pos += 2;
        }
        char_count.erase(maxChar);
        for(auto it = char_count.begin(); it != char_count.end(); ++it) {
            for(int i = 0 ; i < it->second; ++i) {
                if(pos >= S.size()){
                    pos = 1;
                }
                ret[pos] = it->first;
                pos += 2;
            }
        }
        return ret;
    }
};