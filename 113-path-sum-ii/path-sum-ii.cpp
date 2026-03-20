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
    vector<vector<int>> ans;
    int target;

    void dfs(TreeNode *root, vector<int> &temp,  int sum) {
        sum += root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right) {
            if(sum == target) {
                ans.push_back(temp);
            }
        }

        if(root->left)      dfs(root->left, temp, sum);
        if(root->right)     dfs(root->right, temp, sum);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)   return {};

        target = targetSum;
        vector<int> temp;

        dfs(root, temp, 0);

        return ans;
    }
};