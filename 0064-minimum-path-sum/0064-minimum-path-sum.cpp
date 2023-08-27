class Solution {
    

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> prev(n,0);
        vector<int> curr(m,0);
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(row==0 && col==0){
                    curr[col]=grid[row][col];
                    prev[col]=grid[row][col];
                }
                else{
                    int top = INT_MAX;
                    int left = INT_MAX;
                    if(row>0) top = prev[col] + grid[row][col];
                    if(col>0) left = curr[col-1] + grid[row][col];

                    curr[col]=min(top,left);
                    
                    prev=curr;
                }
            }
        }
        
        return prev[m-1];
    }
};