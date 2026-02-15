/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(!root)   return root;

    if(key < root->val)         root->left = deleteNode(root->left, key);

    else if(key > root->val)    root->right = deleteNode(root->right, key);

    else {
        if(!root->left)     return root->right;
        if(!root->right)    return root->left;

        struct TreeNode *node = root->right;
        while(node->left)   node = node->left;

        root->val = node->val;
        root->right = deleteNode(root->right, node->val);
    }

    return root;
}