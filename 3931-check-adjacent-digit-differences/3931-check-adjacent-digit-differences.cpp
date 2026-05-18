class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();

        for(int i = 1; i < n; i++) {
            int num1 = s[i - 1] - '0';
            int num2 = s[i] - '0';
            
            int num = num1 - num2;

            if(num < -2 || num > 2)     return false;
        }

        return true;
    }
};