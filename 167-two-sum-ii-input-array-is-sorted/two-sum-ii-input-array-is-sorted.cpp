class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0, right = n - 1;
        vector<int> ans(2, 0);

        while(left < right) {
            int sum = numbers[left] + numbers[right];

            while(left < right && sum < target) {
                sum = sum - numbers[left++] + numbers[left];
            }

            while(left < right && sum > target) {
                sum = sum - numbers[right--] + numbers[right];
            }

            if(sum == target) {
                return {left + 1, right + 1};
            }
        }

        return {};
    }
};