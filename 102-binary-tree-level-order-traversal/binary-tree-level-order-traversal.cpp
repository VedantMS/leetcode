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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> traversal;

        while(!q.empty()) {
            int level = q.size();
            vector<int> levelElements;

            for(int i = 0; i < level; i++) {
                auto node = q.front();
                if(node->left)      q.push(node->left);
                if(node->right)     q.push(node->right);
                
                levelElements.push_back(node->val);

                q.pop();
            }

            traversal.push_back(levelElements);
        }

        return traversal;
    }
};