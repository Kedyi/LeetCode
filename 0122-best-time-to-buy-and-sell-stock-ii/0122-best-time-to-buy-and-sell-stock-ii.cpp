class Solution {
private:
    int fun(int ind,bool buy, vector<int> &prices,vector<vector<int>> &dp){
        //base case: what is the max price that u can get if u are at index n-1
        if(ind==prices.size()){
            return 0;  
        }
        int profit =0;
        if(dp[ind][buy]!=-1)  return dp[ind][buy];
        if(buy){
            int take = -prices[ind]+fun(ind+1,0,prices,dp);
            int nottake = fun(ind+1,1,prices,dp);
            
           profit = max(take,nottake);
        } 
        
        else{
            int sell = prices[ind]+fun(ind+1,1,prices,dp);
            int notsell = fun(ind+1,0,prices,dp);
            
            profit = max(sell,notsell);
        }
        
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int buy=1;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
         return fun(0,buy,prices,dp);
        }
};