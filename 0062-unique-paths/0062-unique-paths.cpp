class Solution {
private:
    int fun(int i, int j, vector<vector<int>> &dp){
        
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = fun(i-1,j, dp);
        int left = fun(i, j-1, dp);
        
        return dp[i][j] = left+up;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        // dp[0][0]=1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=1;
                
                else{
                    int up=0;
                    if(i>0)
                     up = dp[i-1][j];
                    int left=0;
                    if(j>0)
                     left = dp[i][j-1];

                    dp[i][j] = left+up;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};