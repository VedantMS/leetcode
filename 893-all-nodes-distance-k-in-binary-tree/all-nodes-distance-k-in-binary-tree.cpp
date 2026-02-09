/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parentNode;
        queue<TreeNode*> q;
        
        q.push(root);

        while(!q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                auto top = q.front();
                q.pop();

                if(top->left) {
                    parentNode[top->left->val] = top;
                    q.push(top->left);
                }

                if(top->right) {
                    parentNode[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }

        unordered_map<int, bool> visited;
        
        q.push(target);

        while(k-- && !q.empty()) {
            int level = q.size();

            for(int i = 0; i < level; i++) {
                auto top = q.front();
                q.pop();

                visited[top->val] = true;

                if(top->left && !visited[top->left->val]) {
                    q.push(top->left);
                }

                if(top->right && !visited[top->right->val]) {
                    q.push(top->right);
                }

                if(parentNode[top->val] && !visited[parentNode[top->val]->val]) {
                    q.push(parentNode[top->val]);
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};