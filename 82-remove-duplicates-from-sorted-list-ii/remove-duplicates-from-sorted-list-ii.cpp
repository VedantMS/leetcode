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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = new ListNode(0, head);
        ListNode *left = temp, *right = head;

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
};