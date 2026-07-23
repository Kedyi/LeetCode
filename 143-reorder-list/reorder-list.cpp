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
    void reorderList(ListNode* head) {
        
        stack<ListNode*> st;
        int n=0;
        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
            n++;
        }

        for(int i=0;i<n/2;i++){
            ListNode* temp=head->next;
            ListNode* stacktop = st.top();
            st.pop();
            head->next=stacktop;
            stacktop->next=temp;
            head=temp;
        }

        head->next=NULL;

    }
};