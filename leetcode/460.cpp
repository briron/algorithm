// 460. LFU Cache
// https://leetcode.com/problems/lfu-cache/

class LFUCache {
public:
    unordered_map<int, int> cache;
    unordered_map<int, int> countHash;
    unordered_map<int, list<int>::iterator> iterHash;
    unordered_map<int, list<int>> listHash;
    int pointer = 0;
    int maxCap = 0;
    int curCap = 0;
    
    LFUCache(int capacity) {
        maxCap = capacity;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        
        updateFrequency(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        if(maxCap == 0){
            return;
        }

        if(cache.find(key) != cache.end()) {
            updateFrequency(key);
            cache[key] = value;
            return;
        }

        while(curCap >= maxCap) {
            int erasedKey = *listHash[pointer].begin();

            listHash[pointer].pop_front();
            cache.erase(erasedKey);
            countHash.erase(erasedKey);
            iterHash.erase(erasedKey);

            curCap -= 1;
        }
        
        listHash[0].push_back(key);
        iterHash[key] = --listHash[0].end();
        cache[key] = value;
        countHash[key] = 1;
        
        curCap += 1;
        pointer = 0;
        return;        
    }
    
    void updateFrequency(int key) {
        int count = countHash[key];
        auto it = iterHash[key];

        listHash[count-1].erase(it);
        listHash[count].push_back(key);
        iterHash[key] = --listHash[count].end();
        countHash[key] += 1;

        if(listHash[pointer].size() == 0) {
            pointer += 1;
        }        
        
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */