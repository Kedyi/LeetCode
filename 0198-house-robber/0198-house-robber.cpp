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
        int prev=nums[0];
        int prev2=0;
        //base case 0
        
        for(int ind=1;ind<nums.size();ind++){
            int nottake = 0 + prev;
            int take = nums[ind];
            if(ind>1) take += prev2;
        
            int curr = max(take,nottake); 
            
            prev2=prev;
            prev=curr;
        }
       return prev;
    }
};