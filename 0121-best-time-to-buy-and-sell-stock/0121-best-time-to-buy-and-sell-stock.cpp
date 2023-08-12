class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini =prices[0]; // the day when we buy  
        int mx_profit = 0;
        
        //check which day is best to sell
        for(int i=0;i<prices.size();i++){
            int cost = prices[i]-mini;        
            mx_profit = max(cost,mx_profit);  
            mini = min(mini,prices[i]);       
        }
        
        return mx_profit;
    }
};