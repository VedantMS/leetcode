/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum;

void dfs(struct TreeNode *root, int num) {
    num = num * 10 + root->val;

    if(!root->left && !root->right) {
        sum += num;
        return;
    }

    if(root->left)      dfs(root->left, num);
    if(root->right)     dfs(root->right, num);
}

int sumNumbers(struct TreeNode* root) {
    sum = 0;
    
    dfs(root, 0);

    return sum;
}