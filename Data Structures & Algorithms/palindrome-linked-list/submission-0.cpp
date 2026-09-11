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
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* r=nullptr;
        ListNode* q=nullptr;
        ListNode* p=head;

        while(p){
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }

        head=q;
        return head;
    }

public:
    bool isPalindrome(ListNode* head) {

        if(head==nullptr || head->next==nullptr){
            return true;
        }

        ListNode* q=middleNode(head);

        q=reverseList(q->next);

        ListNode* p=head;

        while(q){
            if(p->val!=q->val){
                return false;
            }

            p=p->next;
            q=q->next;
        }

        return true;
    }
};