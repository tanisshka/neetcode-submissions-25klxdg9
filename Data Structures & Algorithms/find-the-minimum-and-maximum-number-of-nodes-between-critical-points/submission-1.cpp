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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r = head->next->next;

        int cnt = 1;
        int first = -1;
        int prev = -1;
        int minDist = INT_MAX;

        while (r) {
            if ((q->val > p->val && q->val > r->val) || (q->val < p->val && q->val < r->val)) {
                if (first == -1) {
                    first = cnt;
                } else {
                    minDist = min(minDist, cnt - prev);
                }
                prev = cnt;
            }
            p = q;
            q = r;
            r = r->next;
            cnt++;
        }

        if (first == prev) {
            return {-1, -1};
        }

        return {minDist, prev - first};
    }
};
