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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        
        for (ListNode *node = head; node; node = node->next) {
            st.push(node->val);
        }

        int num = st.top();

        ListNode *ans = new ListNode();

        while (!st.empty()) {
            if (st.top() >= num) {
                num = st.top();
                ans->next = new ListNode(st.top(), ans->next);
            }

            st.pop();
        }

        return ans->next;
    }
};