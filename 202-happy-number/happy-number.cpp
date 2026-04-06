class Solution {
public:
    bool isHappy(int n) {
        unordered_set<long> set;

        while(n != 1) {
            int sum = 0;

            while(n > 0) {
                int num = n % 10;
                sum += num * num;
                n /= 10;
            }

            if(set.count(sum)) {
                return false;
            }

            set.insert(sum);
            
            n = sum;
        }

        return true;
    }
};