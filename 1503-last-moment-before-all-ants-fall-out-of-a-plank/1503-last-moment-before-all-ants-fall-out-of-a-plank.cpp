class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int a = -1;
        int b = n + 1;
        
        for (int &num : left) {
            a = max(a, num);
        }

        for (int &num : right) {
            b = min(b, num);
        }
        
        return max(a, n - b);
    }
};