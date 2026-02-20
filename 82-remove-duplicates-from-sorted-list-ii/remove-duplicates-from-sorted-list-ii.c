/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode node, *temp = &node;
    temp->next = head;

    struct ListNode *left = temp, *right = head;

    while(right) {
        if(right->next && right->val == right->next->val) {
            int num = right->val;
            
            while(right && right->val == num) {
                right = right->next;
            }

            left->next = right;
        }

        else {
            left = right;
            right = right->next;
        }
    }

    return temp->next;
}