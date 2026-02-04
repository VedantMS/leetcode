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
    int pairSum(ListNode* head) {
        if(head->next->next == NULL) {
            return head->val + head->next->val;
        }

        ListNode *slow = head, *fast = head->next->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *previousNode = NULL, *presentNode = slow->next, *nextNode;
        while(presentNode) {
            nextNode = presentNode->next;
            presentNode->next = previousNode;
            previousNode = presentNode;
            presentNode = nextNode;
        }

        slow->next = previousNode;
        
        ListNode *num1 = head, *num2 = slow->next;
        int sum = 0, ans = 0;
        while(num2) {
            sum = num1->val + num2->val;
            num1 = num1->next;
            num2 = num2->next;
            ans = max(sum, ans);
        }

        return ans;
    }
};