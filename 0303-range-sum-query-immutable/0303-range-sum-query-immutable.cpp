class NumArray {
public:
    vector<int> a;

    NumArray(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        a = nums;
    }
    
    int sumRange(int left, int right) {
        return a[right] - (left > 0 ? a[left - 1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */