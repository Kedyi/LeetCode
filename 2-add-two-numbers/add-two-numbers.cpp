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
        int carry=0;
        ListNode* l3 = new ListNode(-1);
        ListNode* head=l3;
        while(l2 || l1 || carry){
            ListNode* node = new ListNode(0);
            int temp = carry;
            if(l1){
                temp+=(l1->val);
            }
            if(l2){
                temp+=(l2->val);
            }
            node->val = temp%10;
            carry = temp/10;
            l3->next=node;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            l3=l3->next;
        }
        return head->next;
    }
};