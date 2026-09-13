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
    int countNodes(ListNode* head){
        int cnt=0;
        ListNode* p=head;
        while(p){
            cnt++;
            p=p->next;
        }
        return cnt;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr){
            return head;
        }
        int pos= countNodes(head) - (n - 1);
        ListNode* p=head;
        if(pos==1){
            head=head->next;
            p->next=nullptr;
            return head;
        }

        ListNode* q=nullptr;
        for(int i=1;i<pos;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        p->next=nullptr;
        return head;
    }
};
