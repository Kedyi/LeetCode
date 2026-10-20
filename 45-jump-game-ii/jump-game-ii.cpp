class Solution {

int fun(int ind, vector<int>& nums,vector<int> &dp){
    if(ind>=nums.size()-1){
        return 0;
    }

    if(dp[ind]!=-1) return dp[ind];
    
    int mini = INT_MAX;
    for(int i=1;i<=nums[ind];i++){
        if (ind + i < nums.size()) {
        
        int steps = fun(ind+i,nums,dp);
        
        if (steps != INT_MAX) {
            mini = min(mini,1+steps);
        }
        }
    }

    return dp[ind] = mini;
}

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fun(0,nums,dp);
    }
};