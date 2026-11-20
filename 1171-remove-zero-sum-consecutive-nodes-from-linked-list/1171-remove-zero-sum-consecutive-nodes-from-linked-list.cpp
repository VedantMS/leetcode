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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *node = new ListNode(0, head), *start = node;

        while (start->next) {
            ListNode *temp = start->next;
            int sum = temp->val;

            while (temp && sum) {
                temp = temp->next;
                sum += temp ? temp->val : 0;
            }

            if (temp && !sum) {
                start->next = temp->next;
            }

            else {
                start = start->next;
            }
        }

        return node->next;
    }
};