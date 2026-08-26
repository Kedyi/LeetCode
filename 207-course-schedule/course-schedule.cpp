class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        //Create graph
        for(auto it: prerequisites){
            int course = it[0];
            int prerequisite = it[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        //put nodes with indegree 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){

            int node = q.front();
            q.pop();

            count++;

            for(auto neighbor: adj[node]){
                indegree[neighbor]--;

                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }

        return count==numCourses;
    }
};