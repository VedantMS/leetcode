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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *node = head;
        int n = 0;

        while (node) {
            n++;
            node = node->next;
        }

        node = head;

        int size = n / k, num = n % k;
        vector<ListNode *> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(node);

            int a = size + (i < num ? 1 : 0);
            ListNode *temp = node;

            while (a-- && node) {
                temp = node;
                node = node->next;
            }

            if (temp) {
                temp->next = NULL;
            }
        }

        return ans;
    }
};