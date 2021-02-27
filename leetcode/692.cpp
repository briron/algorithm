// 692. Top K Frequent Words
// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> word_count;
        for(string& word : words) {
            word_count[word] += -1;
        }
        priority_queue<pair<int, string>> pq;
        for(auto it = word_count.begin(); it != word_count.end(); ++it) {
            pq.push({it->second, it->first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<string> ret(k);
        for(int i = k-1 ; i >= 0; --i) {
            ret[i] = pq.top().second;
            pq.pop();
        }
        return ret;
    }
};