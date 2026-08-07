class Solution {

    public void dfs(int row, int col, char target, char[][] board, int[][] vis) {
        board[row][col] = 'Z';
        vis[row][col] = 1;

        int[] dRow = {-1, 0, 1, 0};
        int[] dCol = {0, 1, 0, -1};

        int n = board.length;
        int m = board[0].length;

        for (int k = 0; k < 4; k++) {
            int newRow = row + dRow[k];
            int newCol = col + dCol[k];

            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                vis[newRow][newCol] != 1 &&
                board[newRow][newCol] == target) {

                dfs(newRow, newCol, target, board, vis);
            }
        }
    }

    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;

        char ch = 'O';
        char rep = 'X';

        // Traverse first and last columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == ch) {
                int[][] vis = new int[n][m];
                dfs(i, 0, ch, board, vis);
            }

            if (board[i][m - 1] == ch) {
                int[][] vis = new int[n][m];
                dfs(i, m - 1, ch, board, vis);
            }
        }

        // Traverse first and last rows
        for (int j = 0; j < m; j++) {
            if (board[0][j] == ch) {
                int[][] vis = new int[n][m];
                dfs(0, j, ch, board, vis);
            }

            if (board[n - 1][j] == ch) {
                int[][] vis = new int[n][m];
                dfs(n - 1, j, ch, board, vis);
            }
        }

        // Convert remaining 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == ch) {
                    board[i][j] = rep;
                }
            }
        }

        // Restore marked 'Z' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'Z') {
                    board[i][j] = ch;
                }
            }
        }
    }
}