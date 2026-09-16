/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int countLength(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;

        while (temp) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    ListNode* collisionPoint(ListNode* headA, ListNode* headB, int d) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (d) {
            d--;
            temp2 = temp2->next;
        }

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }

public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int n = countLength(headA);
        int m = countLength(headB);

        if (n < m) {
            return collisionPoint(headA, headB, m - n);
        }
        else {
            return collisionPoint(headB, headA, n - m);
        }
    }
};