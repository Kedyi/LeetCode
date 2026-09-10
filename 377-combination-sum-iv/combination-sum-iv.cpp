class Solution {

private:

    int fun(int target, vector<int>& nums, vector<int> &dp){
        
        //base case
        if(target==0){
            return 1;
        }

        if(dp[target]!=-1) return dp[target];
        
        int ans=0;

        for(int ind=0;ind<nums.size();ind++){
            if(nums[ind]<=target){
                ans+=fun(target-nums[ind], nums, dp);
            }
        }
       
        return dp[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,-1);
        return fun(target, nums, dp);
    }
};