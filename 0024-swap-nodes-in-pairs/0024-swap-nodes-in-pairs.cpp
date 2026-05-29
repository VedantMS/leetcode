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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)        return head;

        ListNode *ans = new ListNode(0, head);
        ListNode *left = ans, *right = head;

        while(right && right->next) {
            left->next = right->next;
            right->next = left->next->next;
            left->next->next = right;
            left = right;
            right = right->next;
        }

        return ans->next;
    }
};