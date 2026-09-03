class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size() / 2;
        unordered_set<int> st;

        for (int &candy : candyType) {
            st.insert(candy);

            if (st.size() == n) {
                return n;
            }
        }

        return st.size();
    }
};