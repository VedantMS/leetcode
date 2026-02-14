/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode *root, int maxVal) {
    if(!root)   return 0;

    int count = 0;
    if(root->val >= maxVal) {
        maxVal = root->val;
        count++;
    }

    return count + dfs(root->left, maxVal) + dfs(root->right, maxVal);
}

int goodNodes(struct TreeNode* root){
    return dfs(root, root->val);
}