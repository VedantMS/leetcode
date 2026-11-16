class Solution {
public:
    void calc(string &s, int k) {
        string str = "";

        for (int i = 0; i < s.size(); i += k) {
            int sum = 0;

            for (int j = i; j < min(i + k, (int) s.size()); j++) {
                sum += s[j] - '0';
            }

            str += to_string(sum);
        }

        s = str;
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            calc(s, k);
        }

        return s;
    }
};