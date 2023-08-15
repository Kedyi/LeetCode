class Solution {
    
private:
    
    bool isCycle(int node, vector<int> adj[], vector<int> &vis,vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto itr: adj[node]){
            if(!vis[itr]){
                if(isCycle(itr,adj,vis,pathVis)==true) return true;
            }
            else if(pathVis[itr]){ //if pathvis of the itr is same which we are traversing
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    
    /*The problem with dfs solution is that if you are given a directed graph that 
    contains a cycle in the solution. The algorithm wont be able to detect, 
    it will spill out an ordering which is wrong. But when using khans algorithm, 
    you will be able to detect whether top. sort was possible or not.
    */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        numCourses = V
        1) draw graph -> adj list
        1 -> 0
        find a toposort
        if toposort contain all vertex then return true
        else false
        */
        vector<int> adj[numCourses];
        //each entry in vecvec show an edge
        for(int i=0;i<prerequisites.size();i++){
            //0,1
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> topo;
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        
        //if cycle present must detect that
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,adj,vis,pathVis)==true) return false;
            }
        }
        
        
        return true;
    }
};