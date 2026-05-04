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

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nxtptr = head->next;
            head->next=prev;
            prev=head;
            head=nxtptr;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        //for even length fast==null
        if(fast!=NULL){
            //odd length so skip middle
            slow=slow->next;
        }
        //reverse second half
        ListNode* secondHalf = reverseLL(slow);
        ListNode* firstHalf = head;

        while(secondHalf){
            if(firstHalf->val!=secondHalf->val) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};