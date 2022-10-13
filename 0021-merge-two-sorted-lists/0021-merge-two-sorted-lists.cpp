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
        if(head1==NULL){
            return head2;
        }
        if(head2==NULL){
            return head1;
        }
       ListNode* dummyhead = new ListNode(0);
       ListNode* temp= dummyhead;
        while(head1!=NULL && head2!=NULL){
            if(head1->val < head2->val){
                temp->next=head1;
                head1=head1->next;
            }
            else{
                temp->next=head2;
                head2=head2->next;
            }
            
                temp=temp->next;
        }
        //h1==null
        if(head1==NULL){
            while(head2!=NULL){
               temp->next=head2;
               head2=head2->next; 
               temp=temp->next;
            }
        }
        //h2==null
        if(head2==NULL){
            while(head1!=NULL){
               temp->next=head1;
               head1=head1->next; 
               temp=temp->next;
            }
        }
        return dummyhead->next;
    }
};












/*
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
*/