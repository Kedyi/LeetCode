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
        if(n==0) return 0;
        //here n is size
        //vector<int> dp(n+1,0); //declare same sise dp array
        //| | | |n | | 
        int prev;
        int prev2;
        int curr;
    
        //loop ->changing para - index(0-2)
        for(int i=0;i<n+1;i++){
            
            //base case
            if(i==0) prev2=i;
            else if(i==1) prev=i;
        
            else{
                
            curr = prev + prev2; 
            cout<<curr<<endl; 
                
            prev2=prev;
            prev = curr;
            }
            
        }
        
        //return sum
        return prev;
    }
};