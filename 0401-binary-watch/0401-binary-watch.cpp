class Solution {
public:
    string isValid(int num) {
        int hour = num >> 6;
        int min = num & 63;

        if (hour >= 12 || min >= 60) {
            return "";
        }

        return to_string(hour) + ":" + (min < 10 ? "0" : "") + to_string(min);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        if (turnedOn == 0) {
            return {"0:00"};
        }

        if (turnedOn > 8) {
            return {};
        }

        vector<string> ans;

        int num = (1 << turnedOn) - 1;

        while (num <(1 << 10)) {
            string time = isValid(num);

            if (!time.empty()) {
                ans.push_back(time);
            }

            int r = num & -num;
            int n = num + r;

            num = (((n ^ num) >> 2) / r) | n;
        }

        return ans;
    }
};