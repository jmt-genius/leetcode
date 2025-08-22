class Solution {
public:
    bool checkcycle(int node,vector<vector<int>> &adj,vector<int> &visited,vector<int> &dfsv){
        visited[node]=1;
        dfsv[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(checkcycle(it,adj,visited,dfsv)) return true;
            }
            else if(dfsv[it]){
                return true;
            }
        }
        dfsv[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> dfsv(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(checkcycle(i,adj,visited,dfsv)) return false;
            }
        }
        return true;
    }
};