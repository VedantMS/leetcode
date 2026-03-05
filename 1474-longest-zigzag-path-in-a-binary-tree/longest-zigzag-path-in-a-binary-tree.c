/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode *node, bool left, int length, int *ans) {
    if(!node) {
        return;
    }

    if(*ans < length) {
        *ans = length;
    }

    if(left) {
        dfs(node->left, false, length + 1, ans);
        dfs(node->right, true, 1, ans);
    }

    else {
        dfs(node->right, true, length + 1, ans);
        dfs(node->left, false, 1, ans);
    }
}

int longestZigZag(struct TreeNode* root) {
    int ans = 0;

    dfs(root, true, 0, &ans);
    dfs(root, false, 0, &ans);

    return ans;
}