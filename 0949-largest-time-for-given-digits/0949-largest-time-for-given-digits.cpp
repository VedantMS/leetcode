class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        string ans = "";

        do {
            if (arr[0] * 10 + arr[1] < 24 && arr[2] < 6) {
                ans = max(ans, to_string(arr[0]) + to_string(arr[1]) + ':' + to_string(arr[2]) + to_string(arr[3]));
            }
        } while (next_permutation(arr.begin(), arr.end()));

        return ans;
    }
};