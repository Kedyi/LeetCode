//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    void bfs(int node,int V, vector<int> adj[],vector<int> &vis,vector<int> &ans){
        //no recursion
        
        //after this fun end for one node we would be able to traverse all connected components
        queue<int> q;
        q.push(node);
        vis[node]=1;
        ans.push_back(node);
        
        while(!q.empty()){
            int ind = q.front();
            q.pop();
            for(auto adjacentNode: adj[ind]){
                if(!vis[adjacentNode]) {
                    q.push(adjacentNode);
                    //if it is added to queue we mark it visited and put in ans
                    vis[adjacentNode]=1;
                    ans.push_back(adjacentNode);
                }
            }
        }
    }
  
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        /*
        0-> {0,1}
        1-> {0,2}
        2-> {0,3}
        3-> {2,4}
        
        start with 0 ->push  all its adj neighbour to queue 
        then pop one by one 
        add to ans 
        mark vis 
        and if not vis push their neighbour
        */
        vector<int> ans;
        vector<int> vis(V,0);
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
                bfs(0,V,adj,vis,ans);
        //     }
        // }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends