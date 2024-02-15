class Solution {
    

public:
    int minPathSum(vector<vector<int>>& grid) {
        // express prob in form of indexes
        int n=grid.size();
        int m=grid[0].size();
        //-1 is coz we are sending indexes
        
        
        //dp size given so no 0;
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        vector<int> prev(m,0);
        vector<int> curr(m,0);
        
        //base, first->last,copy paste
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                
                if(row==0 && col==0) curr[col]=grid[0][0];
                
                else{
                    int up=INT_MAX;
                    if(row>0) up = grid[row][col]+prev[col];
                    
                    int left = INT_MAX;
                    if(col>0) left= grid[row][col] + curr[col-1];
                    
                    
                    curr[col] = min(up,left);
                }
                prev = curr;
            }
        }
        
        return prev[m-1];
    }
};