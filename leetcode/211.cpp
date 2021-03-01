// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/

struct Trie {
    bool isEnd;
    vector<Trie*> children;
    Trie() {
        isEnd = false;
        children = vector<Trie*>(26, NULL);
    }
    void add(string& s, int pos) {
        if(pos == s.size() - 1) {
            isEnd = true;
            return;
        }
        int next = s[pos+1] - 'a';
        if(children[next] == NULL) {
            children[next] = new Trie();
        }
        children[next]->add(s, pos+1);
    }
    bool find(string& s, int pos) {
        if(pos == s.size() - 1) {
            return isEnd;
        }
        if(s[pos+1] == '.') {
            for(int i = 0 ; i < 26 ; ++i) {
                if(children[i] != NULL && children[i]->find(s, pos+1)) {
                    return true;
                }
            }
            return false;
        }
        int next = s[pos+1] - 'a';
        if(children[next] == NULL) {
            return false;
        }
        return children[next]->find(s, pos+1);
    }
};

class WordDictionary {
private:
    Trie* trie = new Trie();
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    void addWord(string word) {
        trie->add(word, -1);
    }
    
    bool search(string word) {
        return trie->find(word, -1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */