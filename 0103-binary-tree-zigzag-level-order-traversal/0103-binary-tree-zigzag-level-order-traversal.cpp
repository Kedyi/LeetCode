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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int dir=1;
         vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL){
                v.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                if(dir==1){
                     ans.push_back(v);
                }
                if(dir==-1){
                    reverse(v.begin(), v.end());
                     ans.push_back(v);
                }
                dir *= -1;
                q.push(NULL);
                v.clear();
            }
        }
           if(dir==1){
                     ans.push_back(v);
                }
                if(dir==-1){
                    reverse(v.begin(), v.end());
                     ans.push_back(v);
                }
    
      return ans;  
    }
};