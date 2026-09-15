class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        sort(deck.begin(), deck.end());

        vector<int> ans(n);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        for (int i = 0; i < n; i++) {
            int index = q.front();
            q.pop();

            ans[index] = deck[i];

            if (!q.empty()) {
                int nextIndex = q.front();
                q.pop();
                q.push(nextIndex);
            }
        }

        return ans;
    }
};