class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum = 0, ans = 0;

        for (int num : arr) {
            sum += num;
            ans += sum % 2;
        }

        return (ans + (arr.size() - ans) * ans) % 1000000007;
    }
};