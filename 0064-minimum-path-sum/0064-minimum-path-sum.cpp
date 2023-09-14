class Solution {
    
private:
    int fun(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &dp){
        
        //base
        if(row==0 && col==0) return grid[0][0];
        
        //memoization
        if(dp[row][col]!=-1) return dp[row][col];
        
        //came from up
        int up = INT_MAX;
        if(row>0) 
            up = grid[row][col] + fun(row-1,col,grid,dp);
        //came from left
        int left = INT_MAX;
        if(col>0)
            left = grid[row][col] + fun(row,col-1,grid,dp);
        
        return dp[row][col] = min(up,left);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return fun(n-1,m-1,grid,dp);
    }
};