class Solution {
public:
    void dfs(int i,int j,char mc,vector<vector<char>> &board,vector<vector<int>> &vis){
        board[i][j]='Z';
        vis[i][j]=1;
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        int n=board.size();
        int m=board[0].size();
        for(int k=0;k<4;k++){
                int trow=i+drow[k];
                int tcol=j+dcol[k];
                if(trow>=0 && trow<n && tcol>=0 && tcol <m && vis[trow][tcol]!=1 && board[trow][tcol]==mc){
                    dfs(trow,tcol,mc,board,vis);
                }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        char ch;
        char rep;
        ch='O';
        rep='X';
        
        for(int i=0;i<n;i++){
            if(board[i][0]==ch){
                vector<vector<int>> vis(n,vector<int>(m,0));
                dfs(i,0,ch,board,vis);
            }
            if(board[i][m-1]==ch){
                vector<vector<int>> vis(n,vector<int>(m,0));
                dfs(i,m-1,ch,board,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]==ch){
                vector<vector<int>> vis(n,vector<int>(m,0));
                dfs(0,i,ch,board,vis);
            }
            if(board[n-1][i]==ch){
                vector<vector<int>> vis(n,vector<int>(m,0));
                dfs(n-1,i,ch,board,vis);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==ch){
                    board[i][j]=rep;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Z'){
                    board[i][j]=ch;
                }
            }
        }

    }
};