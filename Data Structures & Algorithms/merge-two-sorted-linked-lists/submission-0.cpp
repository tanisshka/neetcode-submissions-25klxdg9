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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return nullptr;
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        ListNode dummy(0);
        ListNode* temp=&dummy;

        ListNode* p=list1;
        ListNode* q=list2;
        
        while(p && q){
            if(q->val<=p->val){
                temp->next=q;
                q=q->next;
                temp=temp->next;
            }else{
                temp->next=p;
                p=p->next;
                temp=temp->next;
            }
        }

        if(p){
            temp->next=p;
        }
        if(q){
            temp->next=q;
        }

        return dummy.next;
    }
};
