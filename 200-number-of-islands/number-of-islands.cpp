class Solution {

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
    
    vis[row][col]=1;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};

    for(int k=0;k<4;k++){
        int nrow = drow[k]+row;
        int ncol = dcol[k]+col;

        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && vis[nrow][ncol]==0 &&grid[nrow][ncol]=='1'){
            dfs(nrow, ncol, vis, grid);
        }
    }

}
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    dfs(i,j,vis,grid);
                    ans++;
                }
            }
            
        }

        return ans;
    }
};