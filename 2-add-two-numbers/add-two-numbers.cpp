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
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }

        int carry=0;
        ListNode* dummy= new ListNode(0);
        ListNode* temp = dummy;
        while(l1 || l2 ||carry){
            int sum=0;
            ListNode* node = new ListNode(sum);
            sum+=carry;
            if(l1){
               sum= sum+l1->val;
                l1=l1->next;
            }
            if(l2){
                sum=sum+l2->val;
                l2=l2->next;
            }

            carry = sum/10;
            node->val=sum%10;

            temp->next = node;
            temp=temp->next;
        }

        return dummy->next;
    }
};