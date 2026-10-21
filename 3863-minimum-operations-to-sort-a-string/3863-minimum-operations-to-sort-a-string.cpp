class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (s.size() == 2) {
            return -1;
        }

        auto [low, high] = minmax_element(s.begin() + 1, s.end() - 1);

        if (s[0] <= min(*low, s.back()) || max(s[0], *high) <= s.back()) {
            return 1;
        }

        return s.back() < *low && *high < s[0] ? 3 : 2;
    }
};