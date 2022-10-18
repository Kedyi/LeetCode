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
     int len(ListNode* head){
        if(head==NULL){
            return 0;
        }
        int p=0;
        //1 2 3 4 5
        while(head!=NULL){
            head=head->next;
            p++;
        }
        return p;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        int l1=len(head);
        if(l1<k){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextptr;
        int j=k;
        while(curr!=NULL && j){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
            j--;
        }
        ListNode* newhead = reverseKGroup(curr,k);
        head->next = newhead;
        return prev;
    }
};