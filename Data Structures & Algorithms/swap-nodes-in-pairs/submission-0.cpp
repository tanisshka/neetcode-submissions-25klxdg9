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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* r = dummy;
        ListNode* p = head;
        ListNode* q = head->next;

        while(p && q){
            p->next = q->next;
            q->next = p;
            r->next = q;

            r = p;
            p = p->next;

            if(p){
                q = p->next;
            }
        }

        return dummy->next;
    }
};
