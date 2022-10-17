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
   
    int calHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(calHeight(root->left),calHeight(root->right))+1;
    }
     
  
    int diameterOfBinaryTree(TreeNode* root) {
          if(root==NULL){
          return 0;
      }
      int lHeight = calHeight(root->left);
      int rHeight = calHeight(root->right); 
      int lDiameter = diameterOfBinaryTree(root->left);
      int rDiameter = diameterOfBinaryTree(root->right);
      int currDiameter = lHeight + rHeight;
      return max(currDiameter, max(lDiameter,rDiameter));
        
    }
};