class Solution {
public:
    void dfs(int i,vector<int> &visited,vector<vector<int>> &adj){
        visited[i]=1;
        for(auto j:adj[i]){
            if(visited[j]==0){
                dfs(j,visited,adj);
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(isConnected[i][j]==1){
                    temp.push_back(j);
                }
            }
            adj.push_back(temp);
        }
        vector<int> visited(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};