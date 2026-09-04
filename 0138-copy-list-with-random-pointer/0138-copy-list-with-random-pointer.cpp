/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        vector<int> nums;
        unordered_map<Node *, Node *> mp;

        Node *t = head, *ans = new Node(INT_MAX), *temp = ans;

        while (t) {
            temp->next = new Node(t->val);
            temp = temp->next;
            mp[t] = temp;
            t = t->next;
        }

        t = head;
        temp = ans->next;

        while (t) {
            temp->random = mp[t->random];
            t = t->next;
            temp = temp->next;
        }

        return ans->next;
    }
};