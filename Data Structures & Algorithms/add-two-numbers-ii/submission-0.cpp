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
    ListNode* addTwoRevNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        int carry = 0;

        while (p || q) {
            int sum = 0;
            if (p) {
                sum += p->val;
            }
            if (q) {
                sum += q->val;
            }
            sum += carry;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            carry = sum / 10;

            if (p) {
                p = p->next;
            }

            if (q) {
                q = q->next;
            }
        }

        if (carry) {
            cur->next = new ListNode(carry);
        }

        return dummy->next;
    }

    ListNode* reverse(ListNode* head){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);

        ListNode* head=addTwoRevNumbers(l1,l2);
        head=reverse(head);
        return head;
    }
};