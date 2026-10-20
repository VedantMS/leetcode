class Solution {
public:
    int pivotInteger(int n) {
        int left = 1, right = n, num = (n * (n + 1)) / 2;

        while (left <= right) {
            int mid = (left + right) / 2;

            if ((mid * (mid + 1)) / 2 == num - ((mid - 1) * (mid)) / 2) {
                return mid;
            }

            if ((mid * (mid + 1)) / 2 < num - ((mid - 1) * (mid)) / 2) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return -1;
    }
};