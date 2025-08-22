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
        
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }
        queue<int> q;
        int cnt=0;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }

        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[top]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(cnt==numCourses) return true;
        return false;
    }
};