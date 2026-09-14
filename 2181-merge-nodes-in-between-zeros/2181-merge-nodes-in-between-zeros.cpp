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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *ans = new ListNode(), *t = ans, *node = head;
        int sum = 0;

        while (node) {
            if (node->val == 0) {
                if (sum != 0) {
                    t->next = new ListNode(sum);
                    t = t->next;
                    sum = 0;
                }
            }

            sum += node->val;
            node = node->next;
        }

        return ans->next;
    }
};