class Solution {
private:

    int fun(int ind, int n, vector<int> &dp){

        if(ind==0){
            return 1;
        }
        if(ind<0){
            return 0;
        }

        if(dp[ind]!=-1) return dp[ind];
        
        int onestep=0;
        if(ind>0)
        onestep = fun(ind-1,n, dp);
        int twostep=0;
        if(ind>1)
        twostep = fun(ind-2,n, dp);

        return dp[ind] = onestep+twostep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;

        for(int ind=1;ind<=n;ind++){

            int onestep=0;
            if(ind>0)
            onestep = dp[ind-1];
            int twostep=0;
            if(ind>1)
            twostep = dp[ind-2];

            dp[ind] = onestep+twostep;
        }
        return dp[n];
    }
};