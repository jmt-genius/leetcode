class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size();
        int m=colSum.size();
        vector<int> crowsum(n,0);
        vector<int> ccolsum(m,0);

        vector<vector<int>> matrix(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=min(rowSum[i]-crowsum[i],colSum[j]-ccolsum[j]);
                crowsum[i]+=matrix[i][j];
                ccolsum[j]+=matrix[i][j];
            }
        }
        return matrix;
    }
};