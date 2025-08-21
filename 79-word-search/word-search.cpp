class Solution {
public:
    bool f(int i, int j, int ind, int n, int m, vector<vector<char>>& board, string& word, vector<vector<int>>& visited) {
        // If we've checked all characters in the word, return true
        if (ind == word.size()) {
            return true;
        }
        
        // If out of bounds or the current cell does not match the character, return false
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[ind]) {
            return false;
        }
        
        // Mark this cell as visited
        visited[i][j] = 1;
        
        // Explore all four directions
        bool found = f(i + 1, j, ind + 1, n, m, board, word, visited) ||  // down
                     f(i - 1, j, ind + 1, n, m, board, word, visited) ||  // up
                     f(i, j + 1, ind + 1, n, m, board, word, visited) ||  // right
                     f(i, j - 1, ind + 1, n, m, board, word, visited);    // left
        
        // Unmark this cell as visited for other paths
        visited[i][j] = 0;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));  // Keeps track of visited cells
        
        // Try to find the word starting from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {  // Found the first letter
                    if (f(i, j, 0, n, m, board, word, visited)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
