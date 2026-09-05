class Solution {
private:

    bool fun(int ind, vector<int>& nums, vector<int> &dp){
        if(ind>=nums.size()-1) return true;

        if(dp[ind]!=-1) return dp[ind];
        for(int i=0;i<nums[ind];i++){
            int canjump = nums[ind]-i;
            bool op = fun(canjump+ind, nums,dp);
            if(op==true){
                return dp[ind] = true;
            }
        }

        return dp[ind]= false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),false);

        int n=nums.size();
        dp[n-1]=true;

        for(int ind=n-2;ind>=0;ind--){
           for(int i=0;i<nums[ind];i++){
            int canjump = nums[ind]-i;
            if(canjump+ind<n && dp[canjump+ind]==true){
            bool op = dp[canjump+ind];
            if(op==true){
                dp[ind] = true;
                break;
            }
            }
        }
        }
        return dp[0];
    }
};