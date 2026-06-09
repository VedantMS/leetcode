class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long a = *min_element(nums.begin(), nums.end());
        long long b = *max_element(nums.begin(), nums.end());

        return (b - a) * k;
    }
};