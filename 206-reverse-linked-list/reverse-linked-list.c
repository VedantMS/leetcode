/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *previousNode = NULL, *presentNode, *nextNode = NULL;
    presentNode = head;

    while(presentNode != NULL) {
        nextNode = presentNode->next;
        presentNode->next = previousNode;
        previousNode = presentNode;
        presentNode = nextNode;
    }

    return previousNode;
}