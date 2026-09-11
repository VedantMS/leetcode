class MyLinkedList {
public:
    class node {
        public:
            int val;
            node *next;

            node(int num) {
                val = num;
                next = NULL;
            }

            node(int num, node *t) {
                val = num;
                next = t;
            }
    };

    node *head, *tail;
    int size;

    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size || !head) {
            return -1;
        }

        node *temp = head;

        while (index--) {
            temp = temp->next;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        node *temp = new node(val, head);

        if (!head) {
            tail = temp;
        }

        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        node *temp = new node(val);
        
        if (!tail) {
            head = tail = temp;
            size++;

            return;
        }

        tail->next = temp;
        tail = temp;

        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        
        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        index--;
        
        node *temp = new node(val), *t = head;

        while (index--) {
            t = t->next;
        }

        temp->next = t->next;
        t->next = temp;

        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }

        if (index == 0) {
            node* temp = head;

            head = head->next;
            size--;

            if (size == 0) {
                tail = NULL;
            }

            return;
        }

        index--;

        node *temp = head;

        while (index--) {
            temp = temp->next;
        }

        if (temp->next == tail) {
            tail = temp;
        }

        temp->next = temp->next->next;

        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */