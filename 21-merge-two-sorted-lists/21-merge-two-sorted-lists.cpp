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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* k= new ListNode(0);
        ListNode* dummy = k;
        ListNode* i = head1;
        ListNode* j = head2;
     
    while(i!=NULL && j!=NULL){
        if(i->val < j->val){
            k->next=i;
            i=i->next;
        }
        else{
             k->next=j;
             j=j->next;
        }
        k=k->next;
        }
        
        while(i!=NULL){
            k->next = i;
            i=i->next;
            k=k->next;
        }
        while(j!=NULL){
            k->next = j;
            j=j->next;
            k=k->next;
        }
        
        return dummy->next;
    }
};