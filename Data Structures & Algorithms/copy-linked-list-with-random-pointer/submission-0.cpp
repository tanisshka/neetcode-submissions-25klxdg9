/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void InsertCopyInBetween(Node* head){
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        return;
    }

    void connectRandomPointers(Node* head){
        Node* temp=head;
        while(temp){
            if(temp->random){
                temp->next->random=temp->random->next;
            }else{
                temp->next->random=nullptr;
            }
            temp=temp->next->next;
        }
        return;

    }

    Node* getDeepCopy(Node* head){
        Node* dummy=new Node(-1);
        Node* p=dummy;
        Node* temp=head;

        while(temp){
            p->next=temp->next;
            temp->next=temp->next->next;

            p=p->next;
            temp=temp->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return head;
        }
        InsertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);

    }
};
