
class BrowserHistory {
private:
    struct ListNode {
        ListNode* prev;
        string val;
        ListNode* next;

        ListNode(string val) {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    ListNode* cur;

public:
    BrowserHistory(string homepage) {
        cur = new ListNode(homepage);
    }

    void visit(string url) {
        // Remove forward history
        ListNode* temp = cur->next;

        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        cur->next = nullptr;

        // Create and connect the new page
        ListNode* newNode = new ListNode(url);
        cur->next = newNode;
        newNode->prev = cur;

        cur = newNode;
    }

    string back(int steps) {
        while (steps > 0 && cur->prev != nullptr) {
            cur = cur->prev;
            steps--;
        }

        return cur->val;
    }

    string forward(int steps) {
        while (steps > 0 && cur->next != nullptr) {
            cur = cur->next;
            steps--;
        }

        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */