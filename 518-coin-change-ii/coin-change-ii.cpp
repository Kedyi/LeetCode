class Solution {
int fun(int ind, int amt, vector<int>& coins, vector<vector<int>> &dp){

    //base
    if(amt==0){
        return 1;
    }
    if(ind<0){
        return 0;
    }

    if(dp[ind][amt]!=-1) return dp[ind][amt];

    int take=0;
    if(coins[ind]<=amt){
        take = fun(ind, amt-coins[ind], coins,dp);
    }

    int nottake = fun(ind-1, amt, coins,dp);

    return dp[ind][amt] = take+nottake;
}
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        return fun(n-1,amount,coins,dp);
    }
};