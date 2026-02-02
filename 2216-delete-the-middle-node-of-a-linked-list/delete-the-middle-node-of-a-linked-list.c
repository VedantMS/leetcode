/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode *temp = head;

    int n = 0;
    while(temp != NULL) {
        n++;
        temp = temp->next;
    }

    if(n == 1)  return NULL;

    int middle = n / 2;

    temp = head;
    for(int i = 0; i < middle; i++)  temp = temp->next;

    struct ListNode *temp1 = head;
    for(int i = 0; i < middle - 1; i++)  temp1 = temp1->next;

    temp1->next = temp->next;
    free(temp);

    return head;
}