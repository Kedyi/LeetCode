class Solution {

private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>>& grid){
        
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        for(int k=0;k<4;k++){
            int nrow = i+drow[k];
            int ncol = j+dcol[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, vis, grid);
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                dfs(i, j, vis, grid);
                ans++;
                }
            }
        }

        return ans;
    }
};