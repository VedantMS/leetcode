class SnapshotArray {
public:
    // index, <snapId, value>
    map<int, map<int, int>> snapArray;
    int snapId = 0;
    
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        snapArray[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto &a = snapArray[index];
        auto it = a.upper_bound(snap_id);

        if (it == a.begin()) {
            return 0;
        }
        
        it--;

        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */