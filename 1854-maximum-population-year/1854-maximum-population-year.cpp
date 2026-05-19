class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> arr(101, 0);

        for(auto log : logs) {
            int a = log[0];
            int b = log[1];

            arr[a - 1950]++;
            arr[b - 1950]--;
        }

        int current_pop = 0, max_pop = 0, ans = 1950;
        for(int i = 0; i < 101; i++) {
            current_pop += arr[i];

            if(current_pop > max_pop) {
                max_pop = current_pop;
                ans = 1950 + i;
            }
        }

        return ans;
    }
};