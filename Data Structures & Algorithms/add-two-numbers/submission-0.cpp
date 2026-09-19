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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode dummy(-1);
        ListNode* curr=&dummy;
        int carry=0;

        while(t1 || t2){
            int sum=0;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
            sum+=carry;

            curr->next= new ListNode(sum%10);
            curr=curr->next;

            carry=sum/10;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }

        if(carry){
            curr->next=new ListNode(carry);
        }

        return dummy.next;
    }
};
