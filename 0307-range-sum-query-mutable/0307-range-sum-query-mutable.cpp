class NumArray {
public:
    vector<int> a;
    int num;

    NumArray(vector<int>& nums) {
        num = 1;

        while (num < nums.size()) {
            num <<= 1;
        }

        a.assign(2 * num, 0);

        for (int i = 0; i < nums.size(); i++) {
            a[num + i] = nums[i];
        }

        for (int i = num - 1; i > 0; i--) {
            a[i] = a[2 * i] + a[2 * i + 1];
        }
    }
    
    void update(int index, int val) {
        a[num + index] = val;

        for (int i = (num + index) >> 1; i >= 1; i >>= 1) {
            a[i] = a[2 * i] + a[2 * i + 1];
        }
    }
    
    int sumRange(int left, int right) {
        int ans = 0;

        for (left += num, right += num; left <= right; left >>= 1, right >>= 1) {
            if (left % 2 == 1) {
                ans += a[left++];
            }

            if (right % 2 == 0) {
                ans += a[right--];
            }
        }

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */