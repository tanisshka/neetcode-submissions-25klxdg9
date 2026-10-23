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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* p = dummy;

        while (p->next) {
            if (s.count(p->next->val)) {
                ListNode* temp = p->next;
                p->next = temp->next;
                delete temp;
            } else {
                p = p->next;
            }
        }

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
