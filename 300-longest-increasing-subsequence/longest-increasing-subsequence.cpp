class Solution {
private:

    int fun(int ind,int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        //take
        int take=0;
        if(prev==-1 || nums[prev]>nums[ind])
        take = 1+ fun(ind-1,ind,nums, dp);
        
        //nottake
        int nottake = 0 + fun(ind-1, prev, nums, dp);

        return dp[ind][prev+1] = max(take, nottake);

    }
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int ind=0;ind<n;ind++){
            for(int prev=-1;prev<n;prev++){

            int take=0;
            if((prev==-1 || nums[prev]>nums[ind])){
            take=1;
            if(ind>0)
            take += dp[ind-1][ind+1];
            }
            //nottake
            int nottake=0;
            if(ind>0)
            nottake = 0 + dp[ind-1][prev+1];

            dp[ind][prev+1] = max(take, nottake);

            }
        }
        return dp[n-1][-1+1];
    }
};