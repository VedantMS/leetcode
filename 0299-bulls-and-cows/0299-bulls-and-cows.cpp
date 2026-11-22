class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size(), x = 0, y = 0;
        vector<int> arr(10, 0);

        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                guess[i] = '.';
                
                x++;
            }

            else {
                arr[secret[i] - '0']++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (guess[i] != '.' && arr[guess[i] - '0']) {
                arr[guess[i] - '0']--;
                
                y++;
            }
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};