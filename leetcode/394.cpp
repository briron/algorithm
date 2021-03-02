// 394. Decode String
// https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }
    
    string decode(string& s, int& pos) {
        string ret = "";
        
        while(pos < s.size() && s[pos] != ']') {
            if(!isdigit(s[pos])) {
                ret += s[pos];
                pos += 1;
            }
            else {
                int count = 0;
                while(pos < s.size() && isdigit(s[pos])) {
                    count *= 10;
                    count += s[pos] - '0';
                    pos += 1;
                }
                pos += 1;
                string inner = decode(s, pos);
                pos += 1;
                for(int i = 0 ; i < count ; ++i) {
                    ret += inner;
                }
            }
        }
        return ret;
    }
};
