/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getpath(TreeNode* root, TreeNode* p, vector<TreeNode*> &path){
        if(root==NULL){
            return false;
        }
        path.push_back(root);
        if(root==p){
            return true;
        }
        if(getpath(root->left,p,path) || getpath(root->right,p,path)){
            return true;
        }
        
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return root;
        }
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        if(!getpath(root, p, path1) || !getpath(root, q, path2)){
            return NULL;
        }
        int pc;
        for(pc=0;pc<path1.size() && pc<path2.size();pc++)
        if(path1[pc]!=path2[pc]){
            cout<<path1[pc]->val<< " "<<path2[pc]->val<<endl;
            break;
        }
        
        return path1[pc-1];
    }
};