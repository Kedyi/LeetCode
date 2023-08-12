class Solution {
    
int fun(int ind,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        //base: 0->ind 
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
    
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        //recursion
        int profit=0;
        if(buy){
            int take = -prices[ind] + fun(ind+1,0,cap,prices,dp);
            int nottake = 0 + fun(ind+1,1,cap,prices,dp);
            
            profit = max(take,nottake);
        }
        else{
            int sell = prices[ind]+fun(ind+1,1,cap-1,prices,dp);
            int notsell = 0 + fun(ind+1, 0,cap,prices,dp);
            
            profit = max(sell,notsell);
        }
        //return
    return dp[ind][buy][cap] = profit;
}
    
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(0,1,k,prices,dp);
    }
};