class Solution {

private:

    int fun(int i, int walls, vector<int>& cost, vector<int>& time, vector<vector<int>> &dp){
        if(walls<=0){
            return 0;
        }

        if(i==cost.size()){
            return INT_MAX;
        }

        if(dp[i][walls]!=-1) return dp[i][walls];
        //take paid
        int take = INT_MAX;
        if(fun(i+1,walls-(1+time[i]),cost, time, dp)!=INT_MAX){
            take=cost[i]+fun(i+1,walls-(1+time[i]),cost, time, dp);
        }

        //dont take
        int nottake = fun(i+1, walls, cost, time, dp);

        return dp[i][walls] = min(take,nottake);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return fun(0,n,cost,time,dp);
    }
};