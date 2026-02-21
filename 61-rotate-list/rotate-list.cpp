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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0)     return head;

        ListNode *temp = head;
        int length = 0;
        while(temp) {
            temp = temp->next;
            length++;
        }

        k = k % length;
        if(k == 0)     return head;
        int len = length - k;

        temp = head;
        for(int i = 1; i < len; i++)    temp = temp->next;

        ListNode *temp1 = temp->next;
        while(temp1->next)      temp1 = temp1->next;

        temp1->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};