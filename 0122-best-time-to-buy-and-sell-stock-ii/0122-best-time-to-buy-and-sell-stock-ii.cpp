class Solution {
private:
    int fun(int ind,bool buy, vector<int> &prices,vector<vector<int>> &dp){
        //base case: what is the max price that u can get if u are at index n-1
        if(ind==prices.size()){
            return 0;  
        }
        if(dp[ind][buy]!=-1)  return dp[ind][buy];
        
        int profit =0;
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
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int n=prices.size();
        //base case at 0
        dp[n][0]=dp[n][1]=0; 
        
        //loop
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit =0;
        if(buy){
            int take = -prices[ind]+dp[ind+1][0];
            int nottake = dp[ind+1][1];
            
           profit = max(take,nottake);
        } 
        
        else{
            int sell = prices[ind]+dp[ind+1][1];
            int notsell = dp[ind+1][0];
            
            profit = max(sell,notsell);
        }
                dp[ind][buy]=profit;
            }
        }
        
        //return ans
         return dp[0][1];
        }
};
