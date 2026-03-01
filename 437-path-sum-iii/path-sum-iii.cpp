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
    void dfs(TreeNode *root, long long targetSum, int &ans) {
        if(!root) {
            return;
        }

        if(root->val == targetSum) {
            ans++;
        }

        dfs(root->left, targetSum - root->val, ans);
        dfs(root->right, targetSum - root->val, ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return 0;
        }

        int ans = 0;

        dfs(root, targetSum, ans);
        
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};