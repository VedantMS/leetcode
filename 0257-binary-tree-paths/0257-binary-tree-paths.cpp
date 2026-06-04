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
    void dfs(TreeNode *root, vector<string> &ans, string s) {
        if(s == "")         s += to_string(root->val);

        else                s += "->" + to_string(root->val);

        if(root->left)      dfs(root->left, ans, s);

        if(root->right)     dfs(root->right, ans, s);

        if(!root->left && !root->right) {
            ans.push_back(s);
            return;
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        dfs(root, ans, "");

        return ans;
    }
};