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
    int ans;

    pair<int, int> postorder(TreeNode *root) {
        if (!root) {
            return {0, 0};
        }

        auto [leftSum, leftCount] = postorder(root->left);
        auto [rightSum, rightCount] = postorder(root->right);

        int sum = leftSum + rightSum + root->val;
        int nodes = leftCount + rightCount + 1;

        if (sum / nodes == root->val) {
            ans++;
        }

        return {sum, nodes};
    }

    int averageOfSubtree(TreeNode* root) {
        postorder(root);

        return ans;
    }
};