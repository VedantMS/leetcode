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
    bool isPalindrome(ListNode* head) {
        if(!head->next)     return true;

        ListNode *slow = head, *fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *previous = NULL, *current = slow->next, *next = NULL;

        while(current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        ListNode *left = head, *right = previous;

        while(right) {
            if(left->val != right->val)      return false;

            left = left->next;
            right = right->next;
        }

        return true;
    }
};