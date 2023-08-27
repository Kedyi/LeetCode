class Solution {
    
private:
    int fun(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp){
        //either it would have come from left
        //or top
        // we are taking the element at row and col
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(row==0 && col==0){
            return grid[row][col];
        }
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int top = INT_MAX;
        int left = INT_MAX;
        if(row>0) top = fun(row-1,col,grid,dp) + grid[row][col];
        if(col>0) left = fun(row,col-1,grid,dp) + grid[row][col];
        
        return dp[row][col]=min(top,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0){
                    dp[row][col]=grid[row][col];
                }
                else{
                    int top = INT_MAX;
                    int left = INT_MAX;
                    if(row>0) top = dp[row-1][col] + grid[row][col];
                    if(col>0) left = dp[row][col-1] + grid[row][col];

                    dp[row][col]=min(top,left);
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};