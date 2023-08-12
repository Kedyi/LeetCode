class Solution {
    
private:
    int max_profit(int ind,int buy, vector<int> &prices,vector<vector<int>> &dp){
        //base cases
        if(ind==prices.size()){
            return 0;
        }
        
        if(dp[ind][buy]!=-1)  return dp[ind][buy];
        
        int profit = 0;
        if(buy){
            
            int profit_when_take = -prices[ind] + max_profit(ind+1,0,prices,dp);
            int profit_when_not_take = 0 + max_profit(ind+1,1,prices,dp); 
            
            profit = max(profit_when_take,profit_when_not_take);
        }
        else{
            //sell
            int profit_when_sell = prices[ind] + max_profit(ind+1,1,prices,dp);
            int profit_when_not_sell = 0 + max_profit(ind+1,0,prices,dp);
            
            profit = max(profit_when_sell,profit_when_not_sell);
        }
        
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return max_profit(0,1,prices,dp); //1 means we are allowed to buy
    }
};