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
class compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return (a->val>b->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        //Put all head to minHeap
        for(auto head: lists){
            if(head!=NULL)
               minHeap.push(head);
        }

        //lets create the linked list
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!minHeap.empty()){

            //Get smallest node
            ListNode* node = minHeap.top();
            minHeap.pop();

            //Add to ans
            temp->next=node;
            temp=temp->next;

            // Put next node of same list into heap
            if(node->next!=NULL){
                minHeap.push(node->next);
            }
        }
        return dummy->next;

    }
};