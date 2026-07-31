class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int> a(26, 0);

        for (char &ch : word) {
            a[ch - 'a']++;
        }

        sort(a.rbegin(), a.rend());

        int ans = 0, index = 0;

        for (int i = 0; i < 26 && a[i] > 0; i++) {
            ans += (a[i] * (index / 8 + 1));
            index++;
        }

        return ans;
    }
};