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
    string ans = "|";

    void leaf(TreeNode *root, string s) {
        char ch = root->val + 'a';
        s = ch + s;

        if (!root->left && !root->right) {
            ans = min(ans, s);
            return;
        }

        if (root->left) {
            leaf(root->left, s);
        }

        if (root->right) {
            leaf(root->right, s);
        }
     }

    string smallestFromLeaf(TreeNode* root) {
        leaf(root, "");

        return ans;
    }
};