// 1146. Snapshot Array
// https://leetcode.com/problems/snapshot-array/

class SnapshotArray {
public:
    vector<vector<vector<int>>> arr;
    int version = 0;
    

    SnapshotArray(int length) {
        arr = vector<vector<vector<int>>>(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        if(arr[index].back()[0] == version) {
            arr[index].back()[1] = val;
        } else {
            arr[index].push_back({version, val});
        }
    }
    
    int snap() {
        version += 1;
        return version - 1;
    }
    
    int get(int index, int snap_id) {
        int pos = upper_bound(arr[index].begin(), arr[index].end(), vector<int>({snap_id, INT_MAX})) - arr[index].begin();
        return arr[index][pos-1][1];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */