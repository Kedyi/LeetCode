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
    TreeNode* bstfrompre(vector<int>& preorder, int *preorderIdx,int key, int max, int min, int n){
        if(*preorderIdx>=n){
            return NULL;
        }
        TreeNode* root=NULL;
        if(key>min && key<max){
            root = new TreeNode(key);
           *preorderIdx = *preorderIdx+1;
            if(*preorderIdx<n){
                root->left = bstfrompre(preorder,preorderIdx, preorder[*preorderIdx],key,min,n);
            }
            if(*preorderIdx<n){
                root->right = bstfrompre(preorder,preorderIdx, preorder[*preorderIdx],max,key,n);
            }
        }
        
        return root;
    } 
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderIdx = 0;
       TreeNode* root= bstfrompre(preorder,&preorderIdx,preorder[0],INT_MAX,INT_MIN,preorder.size());
        return root;
    }
};