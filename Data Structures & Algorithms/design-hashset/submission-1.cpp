class MyHashSet {
   private:
    struct ListNode {
        int key;
        ListNode* next;

        ListNode(int key) {
            this->key = key;
            this->next = nullptr;
        }
    };

    vector<ListNode*> set;

    int hash(int key) { return key % set.size(); }

   public:
    MyHashSet() {
        set.resize(10000);

        for (auto& bucket : set) {
            bucket = new ListNode(-1);
        }
    }

    void add(int key) {
        int index = hash(key);
        ListNode* temp = set[index];

        while (temp->next) {
            if (temp->next->key == key) {
                return;
            }
            temp = temp->next;
        }

        temp->next = new ListNode(key);
    }

    void remove(int key) {
        int index = hash(key);
        ListNode* p = set[index];

        while (p->next && p->next->key != key) {
            p = p->next;
        }

        if (p->next) {
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
    }

    bool contains(int key) {
        int index = hash(key);
        ListNode* p = set[index];

        while (p) {
            if (p->key == key) {
                return true;
            }

            p = p->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */