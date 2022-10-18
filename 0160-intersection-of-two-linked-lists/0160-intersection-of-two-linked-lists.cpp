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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        int l1=len(headA);
        int l2=len(headB);
        int d=0;
        ListNode* h1=headA;
        ListNode* h2=headB;
        if(l1>l2){
            d=l1-l2;
            h1=headA;
            h2=headB;
        }
        else{
            d=l2-l1;
            h1=headB;
            h2=headA;
        }
        while(d){
            h1=h1->next;
            d--;
        }
        if(h1==h2){
            return h1;
        }
        while(h1!=NULL && h2!=NULL && h1->next != h2->next){
            h1=h1->next;
            h2=h2->next;
        }
        if(h1==NULL || h2==NULL){
            return NULL;
        }
        return h1->next;
    }
};