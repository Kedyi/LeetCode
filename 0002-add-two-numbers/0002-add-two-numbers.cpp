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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp= dummyHead;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
            }
            if(l2){
                sum+=l2->val;
            }
           
            sum+=carry; //7 0 8
            int nodeval = sum%10;
            carry = sum/10;
            ListNode* n = new ListNode(nodeval);
            cout<< n->val<<endl;
            temp->next=n;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
            temp=temp->next;
        }
        
        return dummyHead->next;
    }
};