class Solution {
    int fun(int ind, vector<int> &nums,vector<int> dp){
        //base case
        if(ind==0) return nums[0];
        
        if(dp[ind]!=-1)  return dp[ind];
        
        int nottake = 0+fun(ind-1,nums,dp);
        int take = nums[ind];
        if(ind>1) take += fun(ind-2,nums,dp);
        
       return dp[ind] = max(take,nottake);
        
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        //base case 0
         dp[0]=nums[0];
        
        for(int ind=1;ind<nums.size();ind++){
            int nottake = 0 + dp[ind-1];
            int take = nums[ind];
            if(ind>1) take += dp[ind-2];
        
            dp[ind] = max(take,nottake); 
        }
       return dp[nums.size()-1];
    }
};