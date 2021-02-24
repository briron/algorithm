struct Trie{
    int cnt;
    vector<Trie*> children;
    Trie() : children(26,NULL), cnt(0) {}
    void insert(string& s, int pos){
        cnt += 1;
        if(s.size() - 1 == pos){
            return;
        }
        int next = s[pos+1] - 'a';
        if(children[next] == NULL){
            children[next] = new Trie();
        }
        children[next]->insert(s, pos+1);
        return;
    }
    int find(string& s, int pos){
        if(s.size() - 1 == pos){
            return 1;
        }
        if(s[pos+1] != '?'){
            int next = s[pos+1] - 'a';
            if(children[next] == NULL){
                return 0;
            }
            return children[next]->find(s, pos+1);
        }
        return cnt;
    }

};

struct Trie {
    bool isEnd;
    vector<Trie*> chilren;
    Trie() {
        chilren = vector<Trie*>(26, NULL);
        isEnd = false;
    }
    void insert(string& s, int pos) {
        if(s.size() - 1 == pos) {
            isEnd = true;
            return;
        }
        int next = s[pos+1] - 'a';
        if(chilren[next] == NULL) {
            chilren[next] = new Trie();
        }
        chilren[next]->insert(s, pos+1);
    }
    bool find(string& s, int pos) {
        if(s.size() - 1 == pos) {
            return isEnd;
        }
        int next = s[pos] - 'a';
        if(chilren[next] == NULL) {
            return false;
        }
        return children[next]->find(s, pos+1);
    }
};