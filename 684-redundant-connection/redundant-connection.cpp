class Solution {
private:

    bool dfs(int u, int v, int parent, vector<int> &vis, vector<vector<int>> &adj){
        if(u==v){
            return true;
        }

        vis[u] = 1;

        for(int neighbour: adj[u]){
            if(!vis[neighbour] && dfs(neighbour, v, u, vis, adj)){
                return true;
            }
        }

        return false;

    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // start building the graph, if two edges are already visited then it will create a cycle
        int n = edges.size();

        vector<vector<int>> adj(n+1);
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            //before creating the edge check if they are connected or not
            vector<int> vis(n+1,0);
            if(dfs(u, v, -1, vis, adj)){
                return edge;
            }

            //else add to adj list
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};