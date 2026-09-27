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

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

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
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }

        // 1. Find the middle node
        ListNode* midNode=middleNode(head);

        // 2. Reverse the second half
        ListNode* q=reverseList(midNode->next);

        // Disconnect the two halves
        midNode->next=nullptr;

        // 3. Reorder the list
        ListNode* p=head;

        while(q){
            ListNode* temp=q;
            q=q->next;

            temp->next=p->next;
            p->next=temp;

            p=p->next->next;
        }
    }
};
