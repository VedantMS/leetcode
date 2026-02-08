/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *t = root, *ans = NULL;
    while(t) {
        if(t->val == val) {
            ans = t;
            return ans;
        }
        else if(t->val > val)    t = t->left;
        else    t = t->right;
    }

    return NULL;
}