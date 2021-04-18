// 1153. String Transforms Into Another String
// https://leetcode.com/problems/string-transforms-into-another-string/

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) {
            return true;
        }
        unordered_map<char, char> conversion;
        unordered_set<char> changed;
        for(int i = 0 ; i < str1.size(); ++i) {
            if(conversion.find(str1[i]) == conversion.end()) {
                conversion[str1[i]] = str2[i];
                changed.insert(str2[i]);
            } else if(conversion[str1[i]] != str2[i]) {
                return false;
            }
        }
        return changed.size() != 26;
    }
};