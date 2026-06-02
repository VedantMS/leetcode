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
    ListNode* partition(ListNode* head, int x) {
        vector<int> a, b;

        ListNode *node = head;

        while(node) {
            int num = node->val;

            if(num < x) {
                a.push_back(num);
            }

            else {
                b.push_back(num);
            }

            node = node->next;
        }

        node = head;

        a.insert(a.end(), b.begin(), b.end());
        int index = 0;

        while(node) {
            node->val = a[index++];
            node = node->next;
        }

        return head;
    }
};