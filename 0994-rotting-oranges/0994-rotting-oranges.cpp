class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        int t=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                     q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int tm=0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int row = it.first.first;
            int col = it.first.second;
            int t = it.second;
            tm = max(tm, t);
            //move in all dirn
            for(int i=0;i<4;i++){
               int nrow = row + drow[i];
               int ncol = col + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};