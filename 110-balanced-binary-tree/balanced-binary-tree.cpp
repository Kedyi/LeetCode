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
int fun(TreeNode* root){
    if(root==NULL) return 0;
    return 1+max(fun(root->left), fun(root->right));
}

public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int left_height = fun(root->left);
        int right_height = fun(root->right);
        if(abs(left_height-right_height)>=2) return false;

        return (isBalanced(root->left)&& isBalanced(root->right));
    }
};