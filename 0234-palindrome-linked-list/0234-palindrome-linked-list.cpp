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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        int n = arr.size();
        for(int i=0,j=n-1;i<n && j>=0;i++,j--){
            if(arr[i]!=arr[j]){
                return false;
            }
        }
        return true;
    }
};