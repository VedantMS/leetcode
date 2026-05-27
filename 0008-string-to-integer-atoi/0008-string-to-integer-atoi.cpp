class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int index = 0;

        while(index < n && s[index] == ' ') {
            index++;
        }

        if(index == n) {
            return 0;
        }

        int num = 1;
        
        if(s[index] == '-') {
            num = -1;
            index++;
        }

        else if(s[index] == '+') {
            index++;
        }
        
        int ans = 0;

        while(index < n && isdigit(s[index])) {
            int digit = s[index] - '0';
            
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return num == 1 ? INT_MAX : INT_MIN;
            }

            ans = ans * 10 + digit;
            index++;
        }

        return ans * num;
    }
};