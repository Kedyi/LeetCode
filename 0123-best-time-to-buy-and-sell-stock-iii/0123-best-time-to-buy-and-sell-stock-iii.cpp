class Solution {
    
    //3d vector: vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)))
private:

    int fun(int ind, int buy, int cap, vector<int>& prices, int n, vector<vector<vector<int>>> &dp){
        if(ind==n || cap==0) return 0;
        
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        
        int profit;
        
        if(buy){
            int take = -prices[ind] + fun(ind+1, 0, cap, prices, n, dp);
            int not_take = 0 + fun(ind+1, 1, cap, prices, n, dp);
            
            profit = max(take, not_take);
        }
        else{
            //allowed to sell
            int take = prices[ind] + fun(ind+1, 1, cap-1, prices, n, dp);
            int not_take = 0 + fun(ind+1, 0, cap, prices,  n, dp);
            
            profit = max(take, not_take);
            
        }
        
        return dp[ind][buy][cap] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
        
        return fun(0, 1, 2, prices,n, dp);
    }
};