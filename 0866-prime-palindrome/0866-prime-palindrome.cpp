class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) {
            return false;
        }

        if (num % 2 == 0) {
            return num == 2;
        }

        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    int primePalindrome(int n) {
        if (n <= 11 && n >= 8) {
            return 11;
        }

        while (1) {
            string s = to_string(n);

            if (s.size() % 2 == 0 && n > 11) {
                n = 1;
                
                for (int i = 0; i < s.size(); i++) {
                    n *= 10;
                }

                continue;
            }

            if (s == string(s.rbegin(), s.rend()) && isPrime(n)) {
                return n;
            }

            n++;
        }

        return 0;
    }
};