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
    bool fun(TreeNode* root,TreeNode* maxallow, TreeNode* minallow){
        if(root==NULL){
            return true;
        }
        if(minallow!=NULL && root->val<=minallow->val){
            return false;
        }
        if(maxallow!=NULL && root->val>=maxallow->val){
            return false;
        }
        bool leftValid = fun(root->left,root,minallow);
        bool rightValid = fun(root->right,maxallow,root);
        
        return leftValid && rightValid;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return fun(root,NULL,NULL);
    }
};