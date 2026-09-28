class Solution {
public:
    int maxDepth(string s) {
        int num = 0, ans = 0;
        
        for (char &ch : s) {
            if (ch == '(') {
                num++;
            }

            else if (ch == ')') {
                num--;
            }

            ans = max(ans, num);
        }

        return ans;
    }
};