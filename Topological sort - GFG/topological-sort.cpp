//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    
    void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node] =1;
        for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    dfs(adjacentNode,adj,vis,st);
                }
        }
        
        st.push(node);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    /* 
	    topoSort using dfs include using
	    1) vis array
	    3) stack
	    
	    start traversing adj list
	    mark vis
	    start dfs on each node
	    after traversal is done push in stack
	    */
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj, vis, st);
	        }
	    }
	    vector<int> topo;
	    while(!st.empty()){
	        int node = st.top();
	        st.pop();
	        topo.push_back(node);
	    }
	    
	    return topo;

	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends