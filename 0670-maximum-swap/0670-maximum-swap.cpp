class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> a(10, 0);

        for (int i = 0; i < s.size(); i++) {
            a[s[i] - '0'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = 9; j > s[i] - '0'; j--) {
                if (a[j] > i) {
                    swap(s[i], s[a[j]]);
                    return stoi(s);
                }
            }
        }

        return stoi(s);
    }
};