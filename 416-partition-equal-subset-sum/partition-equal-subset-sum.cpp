class Solution {

bool fun(int ind, int amt, vector<int>& nums, vector<vector<int>> &dp){
    if(amt==0){
        return true;
    }

    if(ind<0) return false;

    if(dp[ind][amt]!=-1) return dp[ind][amt];

    bool take = false;
    if(nums[ind]<=amt)
    take = fun(ind-1, amt-nums[ind], nums, dp);

    bool nottake = fun(ind-1, amt, nums, dp);

    return dp[ind][amt] = take || nottake;
}
public:
    bool canPartition(vector<int>& nums) {
        //to divide the array in equal subset sum, it should have even sum else we cant divide
        //and if its even then target sum should be equal to sum/2

        int sum=0;
        for(int x: nums) sum+=x;

        if(sum%2!=0) return false;

        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1, -1));

        return fun(nums.size()-1,sum/2, nums, dp);

    }
};