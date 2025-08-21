class Solution {
public:
    bool f(int i, int j, int ind, int n, int m, vector<vector<char>>& board, string& word, vector<vector<int>>& dp) {
        if (ind == word.size()) {
            return true;
        }
        
        if (i < 0 || i >= n || j < 0 || j >= m || dp[i][j] || board[i][j] != word[ind]) {
            return false;
        }
        
        dp[i][j] = 1;
        
        bool found = f(i + 1, j, ind + 1, n, m, board, word, dp) ||  
                     f(i - 1, j, ind + 1, n, m, board, word, dp) ||  
                     f(i, j + 1, ind + 1, n, m, board, word, dp) ||  
                     f(i, j - 1, ind + 1, n, m, board, word, dp);    
        
        dp[i][j] = 0;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (f(i, j, 0, n, m, board, word, dp)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
