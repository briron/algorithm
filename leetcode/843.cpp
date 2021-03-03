// 843. Guess the Word
// https://leetcode.com/problems/guess-the-word/

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<string> left_words(wordlist.begin(), wordlist.end());
        for(int i = 0 ; i < 10; ++i) {
            unordered_map<string, int> counts;
            for(auto& a : left_words) {
                for(auto& b : left_words) {
                    if(match(a, b) == 0) {
                        counts[a] += 1;
                    }
                }
            }
            string candidate = *left_words.begin();
            for(auto& kv : counts) {
                if(counts[candidate] > kv.second) {
                    candidate = kv.first;
                }
            }
            
            int matched = master.guess(candidate);
            if(matched == 6) {
                return;
            }
            unordered_set<string> next_words;
            for(auto& word : left_words) {
                if(match(word, candidate) == matched) {
                    next_words.insert(word);
                } 
            }
            left_words = next_words;
        }
    }
    
    int match(const string& a, const string& b) {
        int ret = 0;
        for(int i = 0 ; i < a.size(); ++i) {
            if(a[i] == b[i]) {
                ret += 1;
            }
        }
        return ret;
    }
};