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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0;
        int l2=0;
        ListNode* temp=headA;
        while(temp){
            l1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            l2++;
            temp=temp->next;
        }
        int n=abs(l1-l2);
        if(l1>l2){
            while(n){
                headA=headA->next;
                n--;
            }
        }
        else{
            while(n){
                headB=headB->next;
                n--;
            }
        }

        while(headA && headB && (headA!=headB)){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};