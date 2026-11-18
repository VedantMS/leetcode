class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;

        for (int num : arr) {
            sum += num;
        }

        if (sum % 3 != 0) {
            return false;
        }

        sum /= 3;

        int ans = 0, n = 0;

        for (int num : arr) {
            n += num;
            
            if (n == sum) {
                ans++;
                n = 0;
            }
        }

        return ans >= 3;
    }
};