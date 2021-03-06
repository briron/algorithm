// 315. Count of Smaller Numbers After Self
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret = vector<int>(nums.size());
        vector<int> sorted = vector<int>(nums.size());
        for(int i = 0 ; i < sorted.size() ; ++i) {
            sorted[i] = i;
        }
        merge_sort(0, sorted.size()-1, sorted, nums, ret);
        return ret;
    }
    
    void merge_sort(int start, int end, vector<int>& sorted, vector<int>& nums, vector<int>& ret) {
        if(start == end) {
            return;
        }
        int mid = (start+end)/2;
        merge_sort(start, mid, sorted, nums, ret);
        merge_sort(mid+1, end, sorted, nums, ret);
        merge(start, end, sorted, nums, ret);
    }
    
    void merge(int start, int end, vector<int>& sorted, vector<int>& nums, vector<int>& ret) {
        int mid = (start+end) / 2;
        vector<int> merged;
        int left_index = start;
        int right_index = mid+1;
        int added = 0;
        while(left_index <= mid && right_index <= end) {
            if(nums[sorted[left_index]] <= nums[sorted[right_index]]) {
                ret[sorted[left_index]] += added;
                merged.push_back(sorted[left_index]);
                ++left_index;
            }
            else{
                added += 1;
                merged.push_back(sorted[right_index]);
                ++right_index;
            }
        }
        
        while(left_index <= mid) {
            ret[sorted[left_index]] += added;
            merged.push_back(sorted[left_index]);
            ++left_index;
        }

        while(right_index <= end) {
            merged.push_back(sorted[right_index]);
            ++right_index;
        }
        
        for(int i = start ; i <= end ; ++i) {
            sorted[i] = merged[i-start];
        }   
    }
};

/* Fenwick Tree / BIT
struct Bit {
    vector<int> tree;
    Bit(int n) {
        tree = vector<int>(n+1);
    }
    int sum(int pos) {
        if(pos < 0) {
            return 0;
        }
        pos += 1;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos -= (pos & -pos);
        }
        return ret;
    }
    void add(int pos, int val) {
        pos += 1;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> vals;
        for(int i = 0 ; i < nums.size(); ++i) {
            vals.insert(nums[i]);
        }
        unordered_map<int, int> val_to_index;
        int index = 0;
        for(auto& val : vals) {
            val_to_index[val] = index;
            index += 1;
        }
        Bit* tree = new Bit(index);
        vector<int> ret(nums.size());
        for(int i = nums.size()-1 ; i >= 0; --i) {
            int val_index = val_to_index[nums[i]];
            ret[i] = tree->sum(val_index-1);
            tree->add(val_index, 1);            
        }
        return ret;
    }
};
*/