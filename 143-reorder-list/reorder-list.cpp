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
    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL) return;

        //half 
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        

        //reverse
        ListNode* prev=NULL;
        ListNode* curr=slow->next;
        slow->next=NULL;
        ListNode* nextptr;

        while(curr){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }

        //newHead= prev
        //merge
        ListNode* dummy= new ListNode(0);
        ListNode* temp=dummy;
        while(head && prev){
            dummy->next=head;
            dummy=dummy->next;
            head=head->next;
            dummy->next=prev;
            dummy=dummy->next;
            prev=prev->next;
        }

        while(head){
           dummy->next=head;
            dummy=dummy->next;
            head=head->next; 
        }
        while(prev){
            dummy->next=prev;
            dummy=dummy->next;
            prev=prev->next;
        }

        head=temp->next;
    }
};