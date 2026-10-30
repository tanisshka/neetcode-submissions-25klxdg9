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
    ListNode* middleNode(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* MergeTwoLists(ListNode* list1, ListNode* list2){
        if(!list1 && !list2){
            return nullptr;
        }else if(!list1){
            return list2;
        }else if(!list2){
            return list1;
        }

        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        ListNode* p=list1;
        ListNode* q=list2;

        while(p && q){
            if(q->val <= p->val){
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

        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* mid=middleNode(head);
        ListNode* lh=head;
        ListNode* rh=mid->next;
        mid->next=nullptr;

        lh=sortList(lh);
        rh=sortList(rh);

        return MergeTwoLists(lh,rh);
    }
};
