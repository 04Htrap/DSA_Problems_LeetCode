class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& visited, vector<vector<char>>& board) {
        visited[row][col] = 1;
        int m = board.size();
        int n = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, visited, board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Traverse first and last row
        for(int i = 0; i < n; i++){
            if(!visited[0][i] && board[0][i] == 'O')
                dfs(0, i, visited, board);
            if(!visited[m - 1][i] && board[m - 1][i] == 'O')
                dfs(m - 1, i, visited, board);
        }

        // Traverse first and last column
        for(int i = 0; i < m; i++){
            if(!visited[i][0] && board[i][0] == 'O')
                dfs(i, 0, visited, board);
            if(!visited[i][n - 1] && board[i][n - 1] == 'O')
                dfs(i, n - 1, visited, board);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};