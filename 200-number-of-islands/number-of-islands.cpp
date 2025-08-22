class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>> &grid){
        visited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        if(i+1<n && !visited[i+1][j] && grid[i+1][j]=='1'){
            dfs(i+1,j,visited,grid);
        }
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]=='1'){
            dfs(i-1,j,visited,grid);
        }
        if(j+1<m && !visited[i][j+1] && grid[i][j+1]=='1'){
            dfs(i,j+1,visited,grid);
        }
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]=='1'){
            dfs(i,j-1,visited,grid);
        }        
                
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(i,j,visited,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};