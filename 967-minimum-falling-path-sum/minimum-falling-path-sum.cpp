class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev = matrix[0];
        vector<int> curr(n);

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int left = (j > 0) ? prev[j-1] : INT_MAX;
                int up = prev[j];
                int right = (j < n-1) ? prev[j+1] : INT_MAX;
                curr[j] = matrix[i][j] + min({left, up, right});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
