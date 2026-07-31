class Solution {
public:
    vector<int> a, b;

    Solution(vector<int>& nums) {
        a = nums;
        b = nums;
    }
    
    vector<int> reset() {
        return a;
    }
    
    vector<int> shuffle() {
        int n = b.size();

        for (int i = 0; i < n; i++) {
            int j = rand() % (i + 1);

            swap(b[i], b[j]);
        }

        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */