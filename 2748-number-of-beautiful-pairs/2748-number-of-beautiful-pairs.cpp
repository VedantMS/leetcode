class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> a(10, 0);

        for (int i = 0; i < n; i++) {
            int last = nums[i] % 10;
            
            for (int j = 1; j <= 9; j++) {
                if (a[j] > 0 && gcd(j, last) == 1) {
                    ans += a[j];
                }
            }

            int first = to_string(nums[i])[0] - '0';
            a[first]++;
        }

        return ans;
    }
};