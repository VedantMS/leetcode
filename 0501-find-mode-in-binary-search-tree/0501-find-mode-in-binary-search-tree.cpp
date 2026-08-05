/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int num;

    void dfs(TreeNode *node, unordered_map<int, int> &mp) {
        mp[node->val]++;

        num = max(num, mp[node->val]);
        
        if (node->left) {
            dfs(node->left, mp);
        }

        if (node->right) {
            dfs(node->right, mp);
        }
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;

        dfs(root, mp);

        vector<int> ans;

        for (auto &[key, value] : mp) {
            if (num == value) {
                ans.push_back(key);
            }
        }

        return ans;
    }
};