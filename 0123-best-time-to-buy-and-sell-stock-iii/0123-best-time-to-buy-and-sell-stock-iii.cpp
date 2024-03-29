class Solution {
    
int fun(int ind,int buy,int cap, vector<int> &prices,vector<vector<vector<int>>> dp){
    if(ind==prices.size()){
        return 0;
    }
    
    if(cap==0){
        return 0;
    }
    
    if(dp[ind][buy][cap]!=-1)  return dp[ind][buy][cap];
    
    int profit = 0;
    if(buy){
        int take = -prices[ind]+fun(ind+1,0,cap,prices,dp);
        int not_take = 0 + fun(ind+1,1,cap,prices,dp);
        
        profit = max(take,not_take);
    }
    else{
        int sell = prices[ind] + fun(ind+1,1,cap-1,prices,dp);
        int not_sell = 0 + fun(ind+1,0,cap,prices,dp);
        
        profit = max(sell,not_sell);
    }
    
    return dp[ind][buy][cap] = profit;
}
public:
    int maxProfit(vector<int>& prices) {
        //changing parameters: ind, buy, cap
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2, vector<int>(3,0)));
        
        for(int ind = prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                dp[ind][buy][0]=0;
            }
        }
        
        for(int buy=0;buy<2;buy++){
                for(int cap = 0;cap<3;cap++){
                    dp[prices.size()][buy][cap]=0;
                }
        }
                
        for(int ind = prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                for(int cap = 1;cap<3;cap++){
                    int profit = 0;
                    if(buy){
                        int take = -prices[ind]+dp[ind+1][0][cap];
                        int not_take = 0 + dp[ind+1][1][cap];

                        profit = max(take,not_take);
                    }
                    else{
                        int sell = prices[ind] + dp[ind+1][1][cap-1];
                        int not_sell = 0 + dp[ind+1][0][cap];

                        profit = max(sell,not_sell);
                    }

                    dp[ind][buy][cap] = profit; 
                }
            }
        }
        return dp[0][1][2];
    }
};