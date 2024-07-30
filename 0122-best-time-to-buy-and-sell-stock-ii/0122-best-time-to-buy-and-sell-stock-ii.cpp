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
        vector<int> curr(2,0);
        vector<int> after(2,0);
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit;
        
                if(buy){
                    int take = -prices[ind] + after[0];
                    int not_take = 0 + after[1];
                    profit = max(take, not_take);
                }
                else{
                    //sell option
                    int take = prices[ind] + after[1];
                    int not_take = 0 + after[0];
                    profit = max(take, not_take);

                }

                curr[buy] = profit;
                after = curr;           
                
            }
        }
        
        return after[1];
    }
};