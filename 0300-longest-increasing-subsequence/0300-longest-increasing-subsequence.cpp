class Solution {
    
int fun(int ind,int prev_ind,int n, vector<int> &nums, vector<vector<int>> &dp){
    //0->n-1
    
    if(ind==n){
        return 0;
    }
    
    if(dp[ind][prev_ind+1]!= -1) return dp[ind][prev_ind+1];
    
    //if i dont want to take the element:
    int not_take = 0 + fun(ind+1,prev_ind,n, nums,dp);
    
    int take=0;
    if(prev_ind == -1 || nums[ind]>nums[prev_ind]){
        take = 1 + fun(ind+1,ind,n, nums,dp);
    }
    return dp[ind][prev_ind+1] = max(take,not_take);
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return fun(0,-1,n,nums,dp);
    }
};