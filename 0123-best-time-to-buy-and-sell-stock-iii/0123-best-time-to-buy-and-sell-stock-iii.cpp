class Solution {
    
int fun(int ind,int buy, vector<int> &prices,int cap,vector<vector<vector<int>>> &dp){
        //base: 0->ind 
        if(cap==0) return 0;
        if(ind==prices.size()) return 0;
    
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        //recursion
        int profit=0;
        if(buy){
            int take = -prices[ind] + fun(ind+1,0,prices,cap,dp);
            int nottake = 0 + fun(ind+1,1,prices,cap,dp);
            
            profit = max(take,nottake);
        }
        else{
            int sell = prices[ind]+fun(ind+1,1,prices,cap-1,dp);
            int notsell = 0 + fun(ind+1, 0,prices,cap,dp);
            
            profit = max(sell,notsell);
        }
        //return
    return dp[ind][buy][cap] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        int buy=1;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return fun(0,buy,prices,2,dp);
    }
};