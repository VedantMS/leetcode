/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count;
int ans;

void inorder(struct TreeNode *root, int k) {
    if(!root || ans != -1)      return;

    inorder(root->left, k);

    if(++count == k) {
        ans = root->val;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    count = 0;
    ans = -1;
    
    inorder(root, k);
    
    return ans;
}