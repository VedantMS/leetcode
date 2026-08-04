class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;

        for (int &num : nums) {
            a.push_back(to_string(num));
        }

        sort(a.begin(), a.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

        string ans = "";

        for (string &s : a) {
            ans += s;
        }

        if (ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};