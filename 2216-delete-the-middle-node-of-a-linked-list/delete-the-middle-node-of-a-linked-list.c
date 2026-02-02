/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    
    struct ListNode *slow = head, *fast = head->next->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *temp = slow->next;
    slow->next = temp->next;
    free(temp);

    return head;
}