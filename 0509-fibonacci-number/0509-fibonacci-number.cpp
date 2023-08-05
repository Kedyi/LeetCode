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
        vector<int> dp(n+1,0); //declare same sise dp array
    
        //loop ->changing para - index(0-2)
        for(int i=0;i<n+1;i++){
            
            //base case
            if(i <= 1) dp[i]=i;
        
            else dp[i] = dp[i-1]+dp[i-2];  
        }
        
        //return sum
        return dp[n];
    }
};