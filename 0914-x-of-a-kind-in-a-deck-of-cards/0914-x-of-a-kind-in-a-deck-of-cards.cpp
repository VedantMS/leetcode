class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int card : deck) {
            mp[card]++;
        }

        for (auto [key, value] : mp) {
            ans = gcd(ans, value);
        }

        return ans > 1;
    }
};