class Solution {
int f(int n,vector<int> &dp){
    if(n<=1) return n;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n]=f(n-1,dp)+f(n-2,dp);
}
public:
    int fib(int n) {
        vector<int> dp(n+1,0);
        int curr;
        int prev;
        int prev2;
        for(int i=0;i<=n;i++){
            
            if(i==0){
               prev2 = 0; 
            }
            else if(i==1) prev = 1;
            
            else{
               curr=prev+prev2;
                prev2=prev;
                prev =curr;
            } 
            
        }
        return prev;
    }
};