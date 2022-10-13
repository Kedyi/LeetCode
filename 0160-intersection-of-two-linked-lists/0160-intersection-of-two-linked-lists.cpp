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
        while(head!=NULL){
            p++;
            head=head->next;
        }
        cout<<p<<endl;
        return p;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==headB){
            return headA;
        }
        int l1=len(headA);
        int l2=len(headB);
        int d = 0;
        ListNode* h1;
        ListNode* h2;
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
        //h1 is the bigger linked list
        while(d){
            h1=h1->next;
            d--;
        }
        int k=0;
        if(h1==NULL){
            return h1;
        }
        if(h1==h2){
            return h1;
        }
        while(h1->next!=h2->next){
            k++;
            h1=h1->next;
            h2=h2->next;
        }
        return h1->next;
    }
};