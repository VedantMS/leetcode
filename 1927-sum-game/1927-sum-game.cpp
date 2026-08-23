class Solution {
public:
    bool sumGame(string num) {
        int leftq = 0, rightq = 0, leftsum = 0, rightsum = 0;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '?') {
                if (i < num.size() / 2) {
                    leftq++;
                }

                else {
                    rightq++;
                }
            }

            else if (i < num.size() / 2) {
                leftsum += num[i] - '0';
            }

            else {
                rightsum += num[i] - '0';
            }
        }

        int qsum = leftq + rightq;

        if (qsum % 2) {
            return true;
        }

        if (qsum == 0) {
            return leftsum != rightsum;
        }

        return 2 * (leftsum - rightsum) != 9 * (rightq - leftq);
    }
};