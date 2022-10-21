/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        
        
        do{
            if(fast->next==NULL || fast->next->next==NULL){
            return false;
        }
            fast=fast->next->next;
            slow=slow->next; 
        }
        while(fast!=NULL && fast!=slow);
        if(fast==NULL){
            return false;
        }
        return true;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head)){
            return NULL;
        }
        if(head==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        do{
            fast=fast->next->next;
            slow=slow->next; 
        } while(fast!=NULL && fast!=slow);
        if(fast==head){
            return head;
        }
       fast = head;
       while(fast->next!=slow->next){
            fast=fast->next;
            slow=slow->next;
        }
       return fast->next; 
    }
};