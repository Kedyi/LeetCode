class Solution {
private:

int fun(int ind, int buy,vector<int>& prices, vector<vector<int>> &dp){
    //base case
    if(ind==prices.size()) return 0;
    
    //memoisation
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit=0;
    
    if(buy){
        int buy_it = -prices[ind]+fun(ind+1,0,prices, dp);
        int do_not_buy_it = 0 + fun(ind+1,1,prices,dp);
        
        profit = max(buy_it, do_not_buy_it);
    }
    else{
        int sell_it = prices[ind]+fun(ind+1,1,prices,dp);
        int do_not_sell_it = 0 + fun(ind+1, 0, prices,dp);
        
        profit = max(sell_it, do_not_sell_it);
    }
    
    return dp[ind][buy] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        
        int buy=1;
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));
        
        
        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
    
                if(buy){
                    int buy_it = -prices[ind]+fun(ind+1,0,prices, dp);
                    int do_not_buy_it = 0 + fun(ind+1,1,prices,dp);

                    profit = max(buy_it, do_not_buy_it);
                }
                else{
                    int sell_it = prices[ind]+fun(ind+1,1,prices,dp);
                    int do_not_sell_it = 0 + fun(ind+1, 0, prices,dp);

                    profit = max(sell_it, do_not_sell_it);
                }

                dp[ind][buy] = profit;
                
                
            }
        }
        
        return dp[0][1];
    }
};