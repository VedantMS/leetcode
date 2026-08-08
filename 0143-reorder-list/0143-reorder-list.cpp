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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *temp = slow;
        slow = slow->next;
        temp->next = NULL;

        ListNode *left = NULL, *node = slow, *right = NULL;

        while (node) {
            right = node->next;
            node->next = left;
            left = node;
            node = right;
        }

        ListNode *a = head, *b = left;

        while (b) {
            ListNode *temp1 = a->next, *temp2 = b->next;
            a->next = b;
            b->next = temp1;
            a = temp1;
            b = temp2;
        }
    }
};