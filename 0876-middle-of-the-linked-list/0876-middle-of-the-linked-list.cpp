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
    
    ListNode* middleNode(ListNode* head) {
        //give length of linked list
        int l = len(head);
        
        //even length - second mid
            l=l/2;
        
        //odd length - mid
        ListNode* temp=head;
       while(l){
           temp=temp->next;
           l--;
       }
        return temp;
    }
};