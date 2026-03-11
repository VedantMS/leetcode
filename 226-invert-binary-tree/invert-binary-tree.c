/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void invert(struct TreeNode *root) {
    if(!root) {
        return;
    }

    struct TreeNode *node = root->left;
    root->left = root->right;
    root->right = node;

    invert(root->left);
    invert(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
    invert(root);

    return root;
}