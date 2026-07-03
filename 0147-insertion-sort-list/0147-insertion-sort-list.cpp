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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> list;
        ListNode *node = head;

        while (node) {
            list.push_back(node->val);
            node = node->next;
        }

        sort(list.begin(), list.end());

        node = head;
        int index = 0;

        while (node) {
            node->val = list[index++];
            node = node->next;
        }

        return head;
    }
};