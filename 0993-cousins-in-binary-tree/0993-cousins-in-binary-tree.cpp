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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int index = q.size();
            bool X = false, Y = false;
            int pX, pY;
            
            for (int i = 0; i < index; i++) {
                auto [u, p] = q.front();
                q.pop();

                if (u->val == x) {
                    X = true;
                    pX = p;
                }

                if (u->val == y) {
                    Y = true;
                    pY = p;
                }

                if (u->left) {
                    q.push({u->left, u->val});
                }

                if (u->right) {
                    q.push({u->right, u->val});
                }
            }

            if (X || Y) {
                if (X && Y && pX != pY) {
                    return true;
                }

                return false;
            }
        }

        return false;
    }
};