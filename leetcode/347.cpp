// 347. Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements/

// quick select
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;
        for(int i = 0 ; i < nums.size() ; ++i) {
            nums_count[nums[i]] += 1;
        }
        vector<vector<int>> sorted_count;
        for(auto it = nums_count.begin(); it != nums_count.end() ; ++it) {
            sorted_count.push_back({it->second, it->first});
        }
        kthLargest(sorted_count, k, 0, sorted_count.size()-1);
        vector<int> ret(k);
        for(int i = 0 ; i < k ; ++i) {
            ret[i] = sorted_count[i][1];
        }
        return ret;
    }
    
    void kthLargest(vector<vector<int>>& nums, int k, int start, int end) {
        int pos = partition(nums, start, end);
        if(pos == k-1) {
            return;
        }
        if(pos > k-1) {
            kthLargest(nums, k, start, pos-1);
            return;
        }
        kthLargest(nums, k, pos+1, end);        
    }
    
    int partition(vector<vector<int>>& nums, int start, int end) {
        int x = nums[end][0];
        int pos = start;
        for(int i = start ; i < end ; ++i) {
            if(nums[i][0] >= x) {
                swap(nums[i], nums[pos]);
                pos += 1;
            }
        }
        swap(nums[pos], nums[end]);
        return pos;
    }
};

/* bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_count;
        for(int i = 0 ; i < nums.size() ; ++i) {
            nums_count[nums[i]] += 1;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for(auto it = nums_count.begin() ; it != nums_count.end() ; ++it) {
            bucket[it->second].push_back(it->first);
        }
        vector<int> ret;
        for(int i = bucket.size() - 1; i >= 0 ; --i) {
            for(int j = 0 ; j < bucket[i].size(); ++j) {
                ret.push_back(bucket[i][j]);
                if(ret.size() == k) {
                    return ret;
                }
            }
        }
        return ret;
    }
};
*/