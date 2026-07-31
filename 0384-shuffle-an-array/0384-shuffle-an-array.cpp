random_device rd;
mt19937_64 gen(rd());

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
        std::shuffle(b.begin(), b.end(), gen);
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */