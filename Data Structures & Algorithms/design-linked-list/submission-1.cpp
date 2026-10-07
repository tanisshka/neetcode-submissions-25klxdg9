class MyLinkedList {
    struct ListNode {
        ListNode* prev;
        int val;
        ListNode* next;

        ListNode(int val) {
            this->prev = nullptr;
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

        if (head == nullptr) {
            head = newNode;
            size++;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
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

        while (p->next != nullptr) {
            p = p->next;
        }

        p->next = newNode;
        newNode->prev = p;

        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
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

        ListNode* newNode = new ListNode(val);

        ListNode* p = head;

        // Move to node at index - 1
        for (int i = 1; i < index; i++) {
            p = p->next;
        }

        newNode->next = p->next;
        newNode->prev = p;

        p->next->prev = newNode;
        p->next = newNode;

        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }


        if (index == 0) {
            ListNode* temp = head;

            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            }

            delete temp;
            size--;

            return;
        }


        ListNode* p = head;

        for (int i = 1; i < index; i++) {
            p = p->next;
        }

        
        ListNode* temp = p->next;

        p->next = temp->next;

        if (temp->next != nullptr) {
            temp->next->prev = p;
        }

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