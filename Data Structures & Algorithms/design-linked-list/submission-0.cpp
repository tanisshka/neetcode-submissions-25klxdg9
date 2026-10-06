class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;

        ListNode(int val, ListNode* next) {
            this->val = val;
            this->next = next;
        }

        ListNode(int val) {
            this->val = val;
            this->next = nullptr;
        }
    };

    ListNode* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        ListNode* p = head;

        for (int i = 0; i < index; i++) {
            p = p->next;
        }

        return p->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);

        newNode->next = head;
        head = newNode;

        size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        ListNode* p = head;

        while (p->next) {
            p = p->next;
        }

        p->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }

        // Insert at beginning
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // Insert at end
        if (index == size) {
            addAtTail(val);
            return;
        }

        ListNode* p = head;

        // Reach node just before index
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        ListNode* newNode = new ListNode(val);

        newNode->next = p->next;
        p->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        // Delete head
        if (index == 0) {
            ListNode* temp = head;
            head = head->next;

            delete temp;
            size--;
            return;
        }

        ListNode* p = head;

        // Reach node just before index
        for (int i = 0; i < index - 1; i++) {
            p = p->next;
        }

        ListNode* temp = p->next;

        p->next = p->next->next;

        delete temp;
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