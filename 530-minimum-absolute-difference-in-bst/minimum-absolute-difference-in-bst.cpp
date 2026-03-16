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
    int ans;
    TreeNode *node;

    void inorder(TreeNode *root) {
        if(root->left)      inorder(root->left);

        if(node)            ans = min(ans, root->val - node->val);

        node = root;

        if(root->right)     inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        ans = INT_MAX;
        node = NULL;
        
        inorder(root);

        return ans;
    }
};