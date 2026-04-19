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
    void deleteNode(ListNode* node) {
        // 1->2->3(node)->4 == 1->2->4
        node->val=node->next->val; //1->2->4(node)->4->null
        node->next=node->next->next; //1->2->4(node)->null
    }
};