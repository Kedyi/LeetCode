class Solution {
int f(int n,vector<int> &dp){
    if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
}
public:
    int fib(int n) {
        vector<int> dp(n+1,0);
        
        for(int i=0;i<=n;i++){
            if(i<=1){
                dp[i] = i; 
            }
            else{
            dp[i]=dp[i-1]+dp[i-2];
            }
            
        }
        return dp[n];
    }
};