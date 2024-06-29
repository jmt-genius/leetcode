class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> g(n);

        for( const auto& edge: edges){
            g[edge[0]].push_back(edge[1]);
        }
        for(int i=0;i<n;i++){
            vector<bool> visit(n,false);
            dfs(g,i,i,res,visit);
        }
        for(int i=0;i<n;i++){
            sort(res[i].begin(),res[i].end());
        }
        return res;

    }
    void dfs(vector<vector<int>>& g,int parent,int curr,vector<vector<int>>& res,vector<bool>&visit){
        visit[curr]=true;
        for(int dest:g[curr]){
            if(!visit[dest]){
                res[dest].push_back(parent);
                dfs(g,parent,dest,res,visit);
            }
        }
    }

};