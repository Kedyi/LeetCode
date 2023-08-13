
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
    
void swap(TreeNode** a, TreeNode** b){
   int temp =  (*a)->val;
   (*a)->val = (*b)->val;
    (*b)->val = temp;
}
  //find the pointer: first, mid,prev, last using inorder   
void calcPointer(TreeNode** prev, TreeNode** first, TreeNode** mid, TreeNode** last, TreeNode* root){
    if(root==NULL){
        return;
    }
    calcPointer(prev,first,mid,last,root->left);
    //if first is null: first = prev, mid  = root;
        //else last : root;
    if(*prev && root->val<(*prev)->val){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    calcPointer(prev,first,mid,last,root->right);
}
public:
    void recoverTree(TreeNode* root) {
        //if swapping is done between apart elements
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* mid = NULL;
        TreeNode* last = NULL;
        
        calcPointer(&prev,&first,&mid,&last,root);
        
        //if swapping is done between adjacent elements  i.e. if last==null : swap(first,mid)
        if(first && last){
            swap(&first, &last);
        }
        //else swap(first,mid) , if(first&mid are not null)
        else if(first && mid){
            swap(&first, &mid);
        } 
    }
};