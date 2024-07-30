class Solution {
    
private:
    
    int fun(int ind, int buy, int n, vector<int>& prices, vector<vector<int>> &dp){
        
        if(ind == n) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        int profit;
        
        if(buy){
            int take = -prices[ind] + fun(ind+1,0,n,prices, dp);
            int not_take = 0 + fun(ind+1,1,n,prices, dp);
            profit = max(take, not_take);
        }
        else{
            //sell option
            int take = prices[ind] + fun(ind+1,1,n,prices, dp);
            int not_take = 0 + fun(ind+1,0,n,prices, dp);
            profit = max(take, not_take);
            
        }
        
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n  = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        
        return fun(0,1,n,prices, dp);
    }
};