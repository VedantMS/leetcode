/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || k == 0) return head;

    int length = 0;
    struct ListNode *temp = head;

    while(temp) {
        temp = temp->next;
        length++;
    }

    k = k % length;
    if(k == 0)      return head;

    int len = length - k;

    temp = head;
    for(int i = 1; i < len; i++)    temp = temp->next;

    struct ListNode *temp1 = temp->next;
    while(temp1->next)      temp1 = temp1->next;

    temp1->next = head;
    head = temp->next;
    temp->next = NULL;

    return head;
}