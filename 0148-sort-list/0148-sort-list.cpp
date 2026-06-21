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
    ListNode* sortList(ListNode* head) {
        if (!head) {
            return NULL;
        }

        vector<int> a;

        ListNode *node = head;

        while (node) {
            a.push_back(node->val);
            node = node->next;
        }

        sort(a.begin(), a.end());

        node = head;

        int index = 0, n = a.size();

        while (index < n) {
            node->val = a[index];
            node = node->next;
            index++;
        }

        return head;
    }
};