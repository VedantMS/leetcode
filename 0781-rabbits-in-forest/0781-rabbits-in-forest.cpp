class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());

        int ans = 0, num = 0;

        for (int i = 0; i < answers.size(); i++) {
            if (answers[i] == 0) {
                ans++;
            }

            else if (i == 0 || answers[i] != answers[i - 1] || num == 0) {
                ans += answers[i] + 1;
                num = answers[i];
            }

            else {
                num--;
            }
        }

        return ans;
    }
};