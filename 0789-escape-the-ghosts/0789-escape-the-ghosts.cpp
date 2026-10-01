class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dist = abs(target[0]) + abs(target[1]);

        for (auto &ghost : ghosts) {
            if (dist >= abs(target[0] - ghost[0]) + abs(target[1] - ghost[1])) {
                return false;
            }
        }

        return true;
    }
};