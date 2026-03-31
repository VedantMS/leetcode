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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            return new TreeNode(val, root, NULL);
        }
        
        queue<TreeNode *> q;
        q.push(root);

        while(depth > 2) {
            int level = q.size();
            depth--;

            for(int i = 0; i < level; i++) {
                auto node = q.front();
                q.pop();

                if(node->left)          q.push(node->left);
                if(node->right)         q.push(node->right);
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            TreeNode *newLeft = new TreeNode(val, node->left, NULL);
            TreeNode *newRight = new TreeNode(val, NULL, node->right);

            node->left = newLeft;
            node->right = newRight;
        }

        return root;
    }
};