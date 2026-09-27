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
    int pairSum(ListNode* head) {
        // 1. Find the first node of the second half
        ListNode* midNode=middleNode(head);

        // 2. Reverse the second half
        ListNode* q=reverseList(midNode);

        // 3. Calculate twin sums
        ListNode* p=head;

        int ans=0;

        while(q){
            int sum=p->val + q->val;
            ans=max(ans,sum);

            p=p->next;
            q=q->next;
        }

        return ans;
    }
};