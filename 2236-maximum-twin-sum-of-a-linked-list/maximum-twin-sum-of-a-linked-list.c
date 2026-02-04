/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int pairSum(struct ListNode* head) {
    if(head->next->next == NULL) {
        return head->val + head->next->val;
    }

    struct ListNode *slow = head, *fast = head->next->next;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *previousNode = NULL, *presentNode = slow->next, *nextNode;
    while(presentNode) {
        nextNode = presentNode->next;
        presentNode->next = previousNode;
        previousNode = presentNode;
        presentNode = nextNode;
    }

    slow->next = previousNode;
        
    struct ListNode *num1 = head, *num2 = slow->next;
    int sum = 0, ans = 0;
    while(num2) {
        sum = num1->val + num2->val;
        num1 = num1->next;
        num2 = num2->next;
        ans = sum > ans ? sum : ans;
    }

    return ans;
}