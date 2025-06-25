class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int left=matrix[i][j];
                if(j-1>=0) left+=dp[i-1][j-1];
                else left+=1e9;
                int right=matrix[i][j];
                if(j+1<=n-1) right+=dp[i-1][j+1];
                else right+=1e9;
                dp[i][j]=min({up,left,right});
            }
        
        }
        int r=1e9;
        for(int i=0;i<n;i++){
            r=min(r,dp[n-1][i]);
        }
        return r;
    }
};