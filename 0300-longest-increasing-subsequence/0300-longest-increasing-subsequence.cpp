class Solution {
    
int fun(int ind, int prev,vector<int> &nums,vector<vector<int>> &dp){
    if(ind==nums.size()){
        return 0;
    }
    if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
    int take = INT_MIN;

    if(prev==-1 || nums[ind]>nums[prev])  
        take = 1 + fun(ind+1,ind,nums,dp);
    
    int not_take = 0 + fun(ind+1,prev,nums,dp);
    
    return dp[ind][prev+1] = max(take,not_take);
}
public:
    int lengthOfLIS(vector<int>& nums) { 
        int n = nums.size();
        //prev data= -1-> 0, 0->1, 1->2
        //ind,prev = 0,-1 -> 0,0, 1,-1 - >1,0
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(0,-1,nums,dp);
    }
};