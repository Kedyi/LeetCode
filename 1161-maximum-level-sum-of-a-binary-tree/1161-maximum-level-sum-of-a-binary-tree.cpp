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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int mxlevel=0;
        int currlevel=0;
        long long mx = INT_MIN;
        long long curr=0;
        //level order traversal
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node!=NULL){
                curr += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                currlevel += 1;
                cout<<curr<< " ";
                if(mx<curr){
                    
                    mxlevel=currlevel;
                 
                    mx = curr;
                }
                curr = 0;
                q.push(NULL);
            }
            
        }
        currlevel += 1;
        // cout<<curr;
        // cout<<mx;
        // cout<<mxlevel;
        // cout<<currlevel;
        if(mx<curr){
            mxlevel = currlevel;
            mx = curr;
        }
        return mxlevel;
    }
};