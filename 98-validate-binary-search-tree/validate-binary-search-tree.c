/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode *root, long minVal, long maxVal) {
    if(!root)   return 1;

    if(root->val <= minVal || root->val >= maxVal)     return 0;

    return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
}

bool isValidBST(struct TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}