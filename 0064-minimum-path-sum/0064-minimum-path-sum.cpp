class Solution {
    

public:
    int minPathSum(vector<vector<int>>& grid) {
        // express prob in form of indexes
        int n=grid.size();
        int m=grid[0].size();
        //-1 is coz we are sending indexes
        
        
        //dp size given so no 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        //base, first->last,copy paste
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                
                if(row==0 && col==0) dp[row][col]=grid[0][0];
                
                else{
                    int up=INT_MAX;
                    if(row>0) up = grid[row][col]+dp[row-1][col];
                    
                    int left = INT_MAX;
                    if(col>0) left= grid[row][col] + dp[row][col-1];
                    
                    
                    dp[row][col] = min(up,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};