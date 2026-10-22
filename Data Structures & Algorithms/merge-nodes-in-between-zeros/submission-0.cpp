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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p=head->next;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;

        while(p){
            int sum=0;
            while(p->val!=0){
                sum+=p->val;
                p=p->next;
            }
            tail->next=new ListNode(sum);
            tail=tail->next;
            p=p->next;
        }
     
        return dummy->next;
    }
};
