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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
           count++; 
            temp=temp->next;
        }
        cout<<count;
        
        count=count-n;
        cout<<count;
        temp=head;
        if(count==0){
            head = temp->next;
            delete temp;
            return head;
        }
        
        while(count>1){
            count--;
            cout<<count;
            temp=temp->next;
        }
        
        temp->next=temp->next->next;
        return head;
    }
};