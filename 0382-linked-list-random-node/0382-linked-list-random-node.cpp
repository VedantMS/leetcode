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
    ListNode *node;

    Solution(ListNode* head) {
        node = head;
    }
    
    int getRandom() {
        int ans, num = 1;
        ListNode *temp = node;

        while (temp) {
            if (rand() % num == 0) {
                ans = temp->val;
            }

            num++;
            temp = temp->next;
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */