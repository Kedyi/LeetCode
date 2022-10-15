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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        /* iterative
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr;
        while(curr!=NULL){
            nextptr = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        head=prev;
        return head;
        */
        
        /* recursive 
         1->2->3->4
        1->2<-3<-4(newhead)
        1-><-2<-3<-4(newhead) now point head to null
        NULL<-1<-2<-3<-4(newhead)
        */
        ListNode* newhead = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
};