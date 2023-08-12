class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int mx_profit=0;
        int mini = prices[0];
        for(int i=0;i<prices.size();i++){
            int cost = prices[i]-mini;
            mx_profit  = max(mx_profit,cost);
            mini = min(mini, prices[i]);
        }
        
        return mx_profit;
    }
};