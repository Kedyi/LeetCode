class Solution {
    
private:
    void f(int index,int target,vector<int> &cand,vector<vector<int>> &ans, vector<int> &curr){
        if(index==cand.size()){
            if(target==0){
                ans.push_back(curr);
            }
            return;
        }
            //pick
            if(cand[index]<=target){
                curr.push_back(cand[index]);
            f(index,target-cand[index],cand,ans,curr);
                curr.pop_back();
            }
            
            //not pick
            f(index+1,target,cand,ans,curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        f(0,target,candidates,ans,curr);
        
        return ans;
    }
};