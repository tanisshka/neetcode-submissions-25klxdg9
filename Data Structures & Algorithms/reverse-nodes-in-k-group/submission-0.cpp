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
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1;

        while (temp && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* r = nullptr;
        ListNode* q = nullptr;
        ListNode* p = head;

        while (p) {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }

        return q;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp) {

            ListNode* kthNode = getKthNode(temp, k);

            if (!kthNode) {
                if (prevNode) {
                    prevNode->next = temp;
                }
                break;
            }

            ListNode* nextNode = kthNode->next;

            kthNode->next = nullptr;

            kthNode = reverseList(temp);

            if (temp == head) {
                head = kthNode;
            }
            else {
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};