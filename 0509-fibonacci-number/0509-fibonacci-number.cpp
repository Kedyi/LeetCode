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
        
        if(n==0)  return 0;
        
        int prev2 = 0;
        int prev = 1;
        
        for(int i=2;i<n+1;i++){
            int curr= prev+prev2;
            
            prev2=prev;
            prev=curr;
        }
        
        return prev;
    }
};