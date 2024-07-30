class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int mini=INT_MAX;
        
        for(int ind = 0;ind<n;ind++){
            mini = min(mini, prices[ind]);
            max_profit= max(max_profit,prices[ind]-mini);
        }
        
        return max_profit;
    }
};