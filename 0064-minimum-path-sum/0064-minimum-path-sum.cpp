class Solution {
    
long long fun(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp){
    
    //if reached dest no need to call function
    if(row==0 && col==0) return grid[0][0];
    
    if(row<0 || col<0) return INT_MAX;
    
    //memo
    if(dp[row][col]!=-1) return dp[row][col];
    
    //f(i,j): give min cost to reach this point
    long long up = grid[row][col]+fun(row-1,col,grid,dp);
    long long left = grid[row][col]+fun(row,col-1,grid,dp);
    
    return dp[row][col] = min(up,left);
}
public:
    int minPathSum(vector<vector<int>>& grid) {
        // express prob in form of indexes
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        //-1 is coz we are sending indexes
        
        
        //dp size given so no -1;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        
        return fun(n,m,grid,dp);
    }
};