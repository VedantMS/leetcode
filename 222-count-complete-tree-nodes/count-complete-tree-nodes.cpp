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
    int count;
    void dfs(TreeNode *root) {
        if(root->left) {
            count++;
            dfs(root->left);
        }

        if(root->right) {
            count++;
            dfs(root->right);
        }
    }

    int countNodes(TreeNode* root) {
        if(!root)   return 0;

        count = 1;

        dfs(root);

        return count;
    }
};