// 358. Rearrange String k Distance Apart
// https://leetcode.com/problems/rearrange-string-k-distance-apart/submissions/

class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1){
            return s;
        }
        vector<int> char_count(26, 0);
        for(int i = 0 ; i < s.size() ; ++i) {
            char_count[s[i] - 'a'] += 1;
        }
        int max_count = 0;
        vector<char> max_char;
        for(int i = 0 ; i < 26 ; ++i){
            if(max_count < char_count[i]) {
                max_count = char_count[i];
                max_char.clear();
            } 
            if(max_count == char_count[i]) {
                max_char.push_back('a' + i);    
            }
        }
        
        if( (max_count - 1) * k + max_char.size() > s.size() ) {
            return "";
        }
        
        if(max_count <= 1) {
            return s;
        }
        
        vector<string> parts(max_count);
        
        for(int i = 0 ; i < max_char.size() ; ++i) {
            parts[max_count - 1] += max_char[i];
        }

        for(int i = 0 ; i < 26; ++i){
            if(max_count - 1 == char_count[i]) {
                max_char.push_back('a' + i);
            }
        }
        
        for(int i = 0 ; i < max_count - 1 ; ++i) {
            for(int j = 0 ; j < max_char.size() ; ++j){
                parts[i] += max_char[j];
            }
        }
        
        int part = 0;
        
        for(int i = 0 ; i < 26 ; ++i) {
            if(char_count[i] >= max_count - 1) {
                continue;
            }
            while(char_count[i] > 0) {
                parts[part] += 'a' + i;
                char_count[i] -= 1;
                part += 1;
                part %= (max_count - 1);
            }   
        }
        
        string ret;
        for(int i = 0 ; i < parts.size(); ++i){
            ret += parts[i];
        }
        
        return ret;
            
    }
};

/* priority queue
class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) {
            return s;
        }

        vector<int> char_count(26, 0);
        for(int i = 0 ; i < s.size() ; ++i) {
            char_count[s[i] - 'a'] += 1;
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0 ; i < 26 ; ++i) {
            if(char_count[i] == 0){
                continue;
            }
            pq.push({char_count[i], 'a' + i});
        }
        deque<pair<int, char>> dq(k-1, {0, ' '});
        string ret;
        for(int i = 0 ; i < s.size() ; ++i) {
            if(pq.size() == 0){
                return "";
            }
            pair<int, char> p = pq.top();
            pq.pop();
            ret += p.second;
            p.first -= 1;
            if(p.first > 0) {
                dq.push_back(p);
            }
            else {
                dq.push_back({0, ' '});
            }
            pair<int, char> ready = dq.front();
            if(ready.first > 0) {
                pq.push(ready);
            }
            dq.pop_front();
        }
        return ret;
    }
};
*/