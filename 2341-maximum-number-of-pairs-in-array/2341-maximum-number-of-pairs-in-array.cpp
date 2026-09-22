class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int &num : nums) {
            freq[num]++;
        }

        vector<int> ans(2, 0);

        for (int &num : freq) {
            ans[0] += num / 2;
            ans[1] += num % 2;
        }

        return ans;
    }
};