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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    
    bool isBalanced(TreeNode* root) {
         if(root==NULL){
            return true;
        }
        int lHeight = maxDepth(root->left);
        int rHeight = maxDepth(root->right);
        if((lHeight== rHeight+1 || lHeight== rHeight || rHeight==lHeight+1 || rHeight==lHeight) && (isBalanced(root->left) && isBalanced(root->right))){
            return true;
        }
        return false;
    }
};