class Solution {
private:
    int countNode(ListNode* head) {
        ListNode* p = head;
        int cnt = 0;

        while (p != nullptr) {
            p = p->next;
            cnt++;
        }

        return cnt;
    }

public:
    ListNode* middleNode(ListNode* head) {
        int n = countNode(head);
        int position = (n / 2) + 1;

        ListNode* p = head;

        for (int i = 1; i < position; i++) {
            p = p->next;
        }

        return p;
    }
};