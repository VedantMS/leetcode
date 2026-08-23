class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1;
        string ans = "";

        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0) + carry;
            
            carry = sum / 10;
            sum = sum % 10;

            ans.push_back((char)(sum + '0'));

            i--;
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};