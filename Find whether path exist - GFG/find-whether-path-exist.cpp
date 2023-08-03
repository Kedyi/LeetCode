//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
       int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int,int>> q;
    int vis[n][m];
    //find the start node
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({i,j});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    } 
    
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    
    while(!q.empty()){
        //q contains rows and cols
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                                            && vis[nrow][ncol]==0 && (grid[nrow][ncol]==3 || grid[nrow][ncol]==2)){
                if(grid[nrow][ncol]==2){
                return 1;
                }
                //neighbour is 3
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
            }
        }
    }
    return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends