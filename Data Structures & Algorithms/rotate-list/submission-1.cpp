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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0){
            return head;
        }
        ListNode* q=head;
        int n=1;
        while(q->next){
            q=q->next;
            n++;
        }

        k=k%n;
        q->next=head;
        k=n-k;

        while(k>0){
            q=q->next;
            k--;
        }
        head=q->next;
        q->next=nullptr;
        return head;

    }
};