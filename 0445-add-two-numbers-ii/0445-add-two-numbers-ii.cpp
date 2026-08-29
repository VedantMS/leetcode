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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *temp = l1;

        while (temp) {
            s1.push(temp->val);
            temp = temp->next;
        }

        temp = l2;

        while (temp) {
            s2.push(temp->val);
            temp = temp->next;
        }

        ListNode *dummy = new ListNode();
        int carry = 0;

        while (!s1.empty() || !s2.empty()) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            carry = sum / 10;
            sum %= 10;

            temp = new ListNode(sum, dummy->next);
            dummy->next = temp;
        }

        if (carry) {
            temp = new ListNode(carry, dummy->next);
            dummy->next = temp;
        }

        return dummy->next;
    }
};