/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        while(!st.empty() || root!=NULL){
            if(root!=NULL){
                st.push(root);
                root=root->left;
            }
            else{
                root=st.top();
                v.push_back(root->val);
                st.pop();
                root=root->right;
            }
        }
        
        return v;
    }
};