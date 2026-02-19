class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long sum = 0, ans = 0;
        
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++) {
            pairs.push_back({nums2[i], nums1[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for(auto &[val2, val1] : pairs) {
            sum += val1;
            minHeap.push(val1);

            if(minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k) {
                ans = max(ans, sum * val2);
            }
        }

        return ans;
    }
};