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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);

        ListNode* lh = left;
        ListNode* rh = right;
        ListNode* p = head;

        while (p) {
            if (p->val < x) {
                lh->next = p;
                p = p->next;
                lh = lh->next;
                lh->next = nullptr;
            } 
            else {
                rh->next = p;
                p = p->next;
                rh = rh->next;
                rh->next = nullptr;
            }
        }

        lh->next = right->next;

        ListNode* result = left->next;

        delete left;
        delete right;

        return result;
    }
};
