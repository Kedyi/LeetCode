class Solution {

public:

    int m,n;

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited){

        visited[row][col]=true;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<4;i++){

            int nrow = row+drow[i];
            int ncol = col+dcol[i];

            //check boundaries
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !visited[nrow][ncol] && heights[nrow][ncol]>=heights[row][col]){ //Move to same or HIGHER height
                dfs(nrow, ncol, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m=heights.size();
        n=heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        //Pacific: Top flow
        for(int i=0;i<n;i++){
            dfs(0,i,heights, pacific);
        }

        //Pacific: Left column
        for(int i=0;i<m;i++){
            dfs(i,0,heights, pacific);
        }

        //Atlantic: Bottom row
        for(int j=0;j<n;j++){
            dfs(m-1,j, heights, atlantic);
        }

        //Atlantic: Right column
        for(int i=0;i<m;i++){
            dfs(i,n-1, heights, atlantic);
        }

        // Find cells reachable by BOTH
        vector<vector<int>> result;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};