class Solution {
    int fun(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }

        if(ind>=coins.size()){
            return INT_MAX;
        }

        if(dp[ind][amount]!=-1) return dp[ind][amount];

        //not take
        int nottake = fun(ind+1, amount, coins,dp);

        //take
        int take = INT_MAX;
        if(amount>=coins[ind])
        {
        if(fun(ind, amount-coins[ind], coins, dp)==INT_MAX) 
            take = INT_MAX;
        else take = 1+ fun(ind, amount-coins[ind], coins,dp);
        }
        return dp[ind][amount] = min(take, nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1,vector<int>(amount+1, -1));
        int ans = fun(0, amount, coins, dp);
        if(ans>=INT_MAX){
            return -1;
        }
        
        return ans;
    }
};