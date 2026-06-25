class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int a = (ax2 - ax1) * (ay2 - ay1);
        int b = (bx2 - bx1) * (by2 - by1);

         if (ax2 < bx1 || ax1 > bx2 || ay2 < by1 || ay1 > by2) {
            return a + b;
         }

         int cx1 = max(ax1, bx1);
         int cy1 = max(ay1, by1);
         int cx2 = min(ax2, bx2);
         int cy2 = min(ay2, by2);

         return a + b - ((cx2 - cx1) * (cy2 - cy1));
    }
};