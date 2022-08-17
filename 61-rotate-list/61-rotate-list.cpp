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
    
    int length(ListNode* head, ListNode* &endptr){
        if(head==NULL){
            return 0;
        }
         if(head->next==NULL){
             return 1;
         }
        
        int l=0;
        while(endptr->next!=NULL){
            endptr=endptr->next;
            l++;
        }
        
        return l+1;
        
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL || k==0){
            return head;
        }
        ListNode* endptr=head;
        int l1=length(head,endptr);
        
        while(l1<k){
            k=k-l1;
        }
        int l=l1-k;
        if(l==0){
            return head;
        }
        ListNode* temp=head;
        while((l-1)>0){
            temp=temp->next;
            l--;
        }
        ListNode* endNode = temp->next;
        endptr->next=head;
        head = endNode;
        head=endNode;
        temp->next=NULL;
        
        return head;
    }
};