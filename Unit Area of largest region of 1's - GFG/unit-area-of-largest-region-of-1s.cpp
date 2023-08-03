//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   private:
    int lengthOfRegion(int row,int col,vector<vector<int>> &grid, vector<vector<int>> &vis){
    int n=grid.size();
    int m=grid[0].size();
    int curr=1;
    vis[row][col]=1;
    int drow[]={-1,-1,0,1,1,1,0,-1};
    int dcol[]={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<8;i++){
        int nrow = row+drow[i];
        int ncol = col+dcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                                        && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
            curr+=lengthOfRegion(nrow,ncol,grid,vis);
        }
    }
    return curr;
}
    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
    
    int n=grid.size();
    int m=grid[0].size();
   vector<vector<int>> vis(n,vector<int>(m,0));
    int mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                int curr=lengthOfRegion(i,j,grid,vis);
                mx = max(mx,curr);
            }
        }
    }
    
    return mx;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends