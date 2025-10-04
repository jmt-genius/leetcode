class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int vis[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        int t=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            t=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int trow=row+drow[i];
                int tcol=col+dcol[i];
                if(trow>=0 && trow<n && tcol>=0 && tcol<m && vis[trow][tcol]==0 && grid[trow][tcol]==1){
                    q.push({{trow,tcol},time+1});
                    vis[trow][tcol]=2;
                }
                
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1) return -1;
            }
        }
        return t;


    }
};