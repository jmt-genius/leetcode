class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> r;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<m;j++){
                mini=min(mini,matrix[i][j]);
            }
            row.push_back(mini);
        }

        vector<int> col;
        for(int i=0;i<m;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                maxi=max(maxi,matrix[j][i]);
            }
            col.push_back(maxi);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==row[i] && matrix[i][j]==col[j]) {
                r.push_back(matrix[i][j]);
                }

            }
        }
        return r;
    }
};