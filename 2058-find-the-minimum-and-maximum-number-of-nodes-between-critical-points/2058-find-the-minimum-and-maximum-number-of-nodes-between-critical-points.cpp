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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode *prev = head, *curn = head->next, *furt = curn->next;
        int index = 1, left = -1, right = -1, mn = INT_MAX;

        while (furt) {
            if (curn->val < prev->val && curn->val < furt->val || curn->val > prev->val && curn->val > furt->val) {
                if (right == -1) {
                    left = index;
                }

                else {
                    mn = min(mn, index - right);
                }

                right = index;
            }

            prev = curn;
            curn = furt;
            furt = furt->next;

            index++;
        }

        if (left == -1 || left == right) {
            return {-1, -1};
        }

        return {mn, right - left};
    }
};