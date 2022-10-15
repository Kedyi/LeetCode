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
        int l=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            l++;
        }
        cout<<l<<endl;
        return l;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = len(head);
        
        ListNode* temp=head;
        //delete head element
        if(l==n){
            head=head->next;
            return head;
        }
        l=l-n-1; //2
        while(l){
            temp=temp->next;
            l--;
        }
        temp->next=temp->next->next;
        return head;
    }
};