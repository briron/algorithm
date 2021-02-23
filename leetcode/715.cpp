// 715. Range Module
// https://leetcode.com/problems/range-module/

class RangeModule {
private:
    map<int,int> ranges;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto lp = ranges.upper_bound(left);
        auto rp = ranges.upper_bound(right);
        if(lp != ranges.begin() && left <= prev(lp)->second){
            --lp;
        }
        if(lp != rp) {
            left = min(left, lp->first);
            right = max(right, prev(rp)->second);
            ranges.erase(lp, rp);
        }
        ranges[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = ranges.upper_bound(left);
        if(it == ranges.begin()){
            return false;
        }
        --it;
        return it->first <= left && right <= it->second;
        
    }
    
    void removeRange(int left, int right) {
        auto lp = ranges.upper_bound(left);
        auto rp = ranges.upper_bound(right);
        if(lp != ranges.begin() && left < prev(lp)->second){
            --lp;
        }
        if(lp == rp) {
            return;
        }
        int left_bound = lp->first;
        int right_bound = prev(rp)->second;
        ranges.erase(lp, rp);
        if(left_bound < left) {
            ranges[left_bound] = left;
        }
        if(right < right_bound) {
            ranges[right] = right_bound;
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */