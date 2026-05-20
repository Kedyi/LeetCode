class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int tm= 0;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>,int>> q;
        //keep all rotten oranges list
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            //extract all rotten orange
            auto obj = q.front();
            int row= obj.first.first;
            int col= obj.first.second;
            int t = obj.second;
            vis[row][col]=2;
            q.pop();
            tm= max(tm, t);
            

            //traverse and rot all surrounding
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};

            for(int k=0; k<4;k++){
                int nrow = row+drow[k];
                int ncol = col+dcol[k];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    grid[nrow][ncol]=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return tm;
    }
};