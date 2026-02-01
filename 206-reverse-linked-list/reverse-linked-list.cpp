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
    ListNode* reverseList(ListNode* head) {
        ListNode *previousNode = NULL, *presentNode, *nextNode = NULL;
        presentNode = head;

        while(presentNode != NULL) {
            nextNode = presentNode->next;
            presentNode->next = previousNode;
            previousNode = presentNode;
            presentNode = nextNode;
        }

        return previousNode;
    }
};