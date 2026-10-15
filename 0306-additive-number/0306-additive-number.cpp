class Solution {
public:
    bool dfs(int index, long long p1, long long p2, int count, string &num) {
        if (index == num.size()) {
            return count > 2;
        }

        long long n = 0;

        for (int i = index; i < num.size(); i++) {
            if (i > index && num[index] == '0') {
                break;
            }

            long long digit = num[i] - '0';

            if (n > (LLONG_MAX - (num[i] - '0')) / 10) {
                break;
            }

            n = n * 10 + digit;

            if (count < 2) {
                if (dfs(i + 1, p2, n, count + 1, num)) {
                    return true;
                }
            }

            else {
                long long sum = p1 + p2;

                if (n > sum) {
                    break;
                }

                if (n == sum) {
                    if (dfs(i + 1, p2, n, count + 1, num)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
    
    bool isAdditiveNumber(string num) {
        return dfs(0, 0, 0, 0, num);
    }
};