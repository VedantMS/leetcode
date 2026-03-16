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
    vector<int> nums;

    void inorder(TreeNode *root) {
        if(root->left)      inorder(root->left);
        nums.push_back(root->val);
        if(root->right)     inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);

        int ans = INT_MAX;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            ans = min(ans, abs(nums[i] - nums[i - 1]));
        }

        return ans;
    }
};