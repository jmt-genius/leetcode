class Solution {
public:
    bool dfs(int i,int col,vector<int> &visited,vector<vector<int>> &graph){
        visited[i]=col;
        for(auto it:graph[i]){
            if(visited[it]==-1){
                if(dfs(it,!col,visited,graph)==false) return false; 
            }
            else if(visited[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(dfs(i,0,visited,graph)==false) return false;
            }
        }
        return true;
    }
};