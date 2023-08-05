class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //base case at 0
        int mini = prices[0];
        int profit = 0; //0 profit at index 0
            
        for(int i=1;i<prices.size();i++){
            int cost = prices[i]-mini;
            profit = max(profit,cost);
            mini = min(prices[i],mini);
            
        }
        
        return profit;
    }
};