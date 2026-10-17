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
private:
    int minDistcalc(vector<int> index) {
        int minDist = INT_MAX;

        for (int i = 1; i < index.size(); i++) {
            minDist = min(minDist, index[i] - index[i - 1]);
        }

        return minDist;
    }

    int maxDistcalc(vector<int> index) {
        int n = index.size() - 1;
        return index[n] - index[0];
    }

public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head->next;
        ListNode* r = head->next->next;

        if (!r) {
            return {-1, -1};
        }

        int cnt = 1;
        vector<int> index;

        while (r) {
            if ((q->val > p->val && q->val > r->val) ||
                (q->val < p->val && q->val < r->val)) {
                index.push_back(cnt);
            }

            p = q;
            q = r;
            r = r->next;
            cnt++;
        }

        if (index.size() < 2) {
            return {-1, -1};
        }

        int minDist = minDistcalc(index);
        int maxDist = maxDistcalc(index);

        return {minDist, maxDist};
    }
};

