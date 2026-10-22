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
    ListNode* removeNodes(ListNode* head) {
       //Monotonic stack
       stack<ListNode*> st;
       ListNode* p=head;

        while(p){
          while(!st.empty() && st.top()->val < p->val){
            st.pop();
          }
          st.push(p);
          p=p->next;
        }

        ListNode* dummy=new ListNode(0);

        while(!st.empty()){
            ListNode* node=st.top();
            st.pop();

            node->next=dummy->next;
            dummy->next=node;
        }

        return dummy->next;
    }
};
