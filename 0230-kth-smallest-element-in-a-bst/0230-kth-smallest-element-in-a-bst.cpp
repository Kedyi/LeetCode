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
    
private:
    void fun(TreeNode* root,int* k,int* ans){
     if(root==NULL){
         return;
     }
        fun(root->left,k,ans);
        *k = *k-1;
        
        if(*k==0){
            *ans = root->val;
        }
        fun(root->right,k,ans);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
       if(root==NULL){
           return -1;
       }
        int ans=0;
        fun(root,&k,&ans);
        return ans;
    }
};