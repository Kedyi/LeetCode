class Solution {

int fun(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){

    if(amt==0){
        return 0;
    }

    if(ind<0){
        return INT_MAX;
    }

    if(dp[ind][amt]!=-1) return dp[ind][amt];

    //take
    int take = INT_MAX;
    if(amt>=coins[ind]){
    if(fun(ind, amt-coins[ind], coins, dp)!=INT_MAX)
        take = 1+ fun(ind, amt-coins[ind], coins, dp);
    }
    //nottake
    int nottake = 0 + fun(ind-1, amt, coins, dp);

    return dp[ind][amt] = min(take,nottake);
}


public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX));

        int ans = INT_MAX;

        //first column->amount==0 base case
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }

        //first row->last index 0 , can we form using that
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
        }


        for(int ind=1;ind<n;ind++){
            for(int amt=1;amt<=amount;amt++){

                int take = INT_MAX;
                if(amt>=coins[ind]){
                if(dp[ind][amt-coins[ind]]!=INT_MAX)
                    take = 1+ dp[ind][amt-coins[ind]];
                }
                //nottake
                int nottake = 0 + dp[ind-1][amt];

                dp[ind][amt] = min(take,nottake);

            }
        }

        ans = dp[n-1][amount];

        return ans==INT_MAX?-1:ans;
    }
};