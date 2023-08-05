class Solution {
    
private:
    int fibonacciAtn(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fibonacciAtn(n-1, dp)+fibonacciAtn(n-2, dp);
    }
public:
    int fib(int n) {
        //here n is size
        vector<int> dp(n+1,-1);
        return fibonacciAtn(n,dp);
    }
};