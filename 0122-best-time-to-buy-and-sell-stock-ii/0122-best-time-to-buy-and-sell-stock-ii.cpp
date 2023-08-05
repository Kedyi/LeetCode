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
        int n=prices.size();
        
        vector<int> dp(2,0);
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        //base case at 0
        dp[0]=dp[1]=0; 
        
        //loop
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit =0;
        if(buy){
            int take = -prices[ind]+dp[0];
            int nottake = dp[1];
            
           profit = max(take,nottake);
        } 
        
        else{
            int sell = prices[ind]+dp[1];
            int notsell = dp[0];
            
            profit = max(sell,notsell);
        }
                dp[buy]=profit;
            }
        }
        
        //return ans
         return dp[1];
        }
};
