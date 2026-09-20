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
    int cntNodes(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        int n=cntNodes(head);
        k=k % n;
        if(k==0){
            return head;
        }
        k=n - k - 1;
        ListNode* temp=head;
        ListNode* p=head;
        ListNode* q=head;

        while(q->next){
            q=q->next;
        }
        
        while(k>0){
            temp=temp->next;
            k--;
        }
        head=temp->next;
        temp->next=nullptr;
        q->next=p;
        return head;
    }
};