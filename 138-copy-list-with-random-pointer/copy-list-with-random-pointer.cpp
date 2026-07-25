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
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;

        Node* temp = head;
        //A->A`->B->B`
        while(temp){
            Node* nxtNode = temp->next;
            temp->next=new Node(temp->val);
            temp->next->next=nxtNode;
            temp=nxtNode;
        }

        //put random pointer
        temp=head;
        while(temp!=NULL){
            if(temp->random!=NULL)
              temp->next->random = temp->random->next;

            temp=temp->next->next;
        }

        //put next values, which will seperate the originals
        temp=head;
        Node* copyHead=temp->next;

        while(temp){
            // A-A`-B-B`-C-C`-D-D`
            Node* copy = temp->next;

            // Restore original list
            temp->next=copy->next;

            // Connect copied list
            if(copy->next!=NULL){
                copy->next=copy->next->next;
            }

            temp=temp->next;

        }

        return copyHead;

    }
};