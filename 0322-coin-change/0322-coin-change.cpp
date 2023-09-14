class Solution {
    
private:
    int fun(int ind, int amt, vector<int>& coins, vector<vector<int>> &dp){
        
        if(amt==0) return 0;
        
        if(ind<0) return INT_MAX;
        
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        
        int not_take = 0 + fun(ind-1,amt, coins,dp);
        
        int take = INT_MAX;
        if(amt>=coins[ind]) {
            
            if(fun(ind, amt-coins[ind] ,coins,dp)==INT_MAX) take=INT_MAX;
            
            else take = 1 + fun(ind, amt-coins[ind] ,coins,dp);
        }
        
        return dp[ind][amt] = min(take,not_take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
      //return condition_1 ? a : b;
        int n = coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
            
        int ans = fun(n-1,amount,coins,dp);
        return ans == INT_MAX ? -1 : ans;
    }
};