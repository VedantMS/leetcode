/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode *root, int *leaves, int *index) {
    if(!root->left && !root->right) {
        leaves[(*index)++] = root->val;
        return;
    }

    if(root->left)      dfs(root->left, leaves, index);
    if(root->right)     dfs(root->right, leaves, index);
}
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *leaves1 = (int *)malloc(200 * sizeof(int));
    int *leaves2 = (int *)malloc(200 * sizeof(int));
    
    int index1 = 0;
    int index2 = 0;

    dfs(root1, leaves1, &index1);
    dfs(root2, leaves2, &index2);
    
    if(index1 != index2)    return 0;

    for(int i = 0; i < index1; i++) {
        if(leaves1[i] != leaves2[i])  return 0;
    }

    return 1;
}