class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = 0;
        int w = sqrt(area);

        while (area % w > l) {
            w -= 1;
        }

        l = area / w;

        return {l, w};
    }
};