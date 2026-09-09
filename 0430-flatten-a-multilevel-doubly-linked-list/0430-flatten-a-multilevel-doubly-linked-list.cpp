/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *node = head;

        while (node) {
            if (node->child) {
                Node *temp = node->next;
                node->next = flatten(node->child);
                
                Node *t = node->child;
                t->prev = node;

                while (t->next) {
                    t = t->next;
                }

                t->next = temp;
                
                if (temp) {
                    temp->prev = t;
                }

                node->child = NULL;
            }

            node = node->next;
        }

        return head;
    }
};