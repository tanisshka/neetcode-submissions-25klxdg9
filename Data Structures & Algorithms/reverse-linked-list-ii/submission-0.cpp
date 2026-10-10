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
    ListNode* reverse(ListNode* temp){
        ListNode* p=temp;
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right){
            return head;
        }

        ListNode* l=head;
        ListNode* t=nullptr;

        for(int i=1;i<left;i++){
            t=l;
            l=l->next;
        }
        
        ListNode* r=l;
        for(int i=left;i<right;i++){
            r=r->next;
        }

        ListNode* temp=r->next;
        r->next=nullptr;

        ListNode* newHead=reverse(l);

        if(t==nullptr){
            head=newHead;
        }else{
            t->next=newHead;
        }
        l->next=temp;
        return head;
        
    }
};