class Solution {
public:
    void dfs(vector<vector<int>> &grid,int m,int n,vector<vector<int>> &visited){
        visited[m][n]=1;
        grid[m][n]=2;
        int ml=grid.size();
        int nl=grid[0].size();
        vector<int> drow={1,-1,0,0};
        vector<int> dcol={0,0,-1,1};
        for(int i=0;i<4;i++){
            int row=m+drow[i];
            int col=n+dcol[i];
            if(row>=0 && row<ml && col>=0 && col<nl){
                if(visited[row][col]==0 && grid[row][col]==1){
                    dfs(grid,row,col,visited);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) dfs(grid,i,0,visited);
            if(grid[i][n-1]==1) dfs(grid,i,n-1,visited);
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) dfs(grid,0,i,visited);
            if(grid[m-1][i]==1) dfs(grid,m-1,i,visited);
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};