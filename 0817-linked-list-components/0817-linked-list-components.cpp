/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        vector<bool> a(10001, false);
        
        for (int &num : nums) {
            a[num] = true;
        }

        ListNode *node = head;
        int ans = nums.size();

        while (node->next) {
            if (a[node->val] && a[node->next->val]) {
                ans--;
            }

            node = node->next;
        }

        return ans;
    }
};