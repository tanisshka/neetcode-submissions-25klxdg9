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
    ListNode* reverseList(ListNode* head){
        ListNode* p=head;
        ListNode* q=nullptr;
        ListNode* r=nullptr;

        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        return q;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        head=reverseList(head);
        int maxVal=INT_MIN;
        ListNode* cur=head;
        ListNode* p=nullptr;

        while(cur){
            if(cur->val < maxVal){
                p->next=cur->next;
            }else{
                maxVal=cur->val;
                p=cur;
            }
            cur=cur->next;
        }

        return reverseList(head);
        
    }
};
