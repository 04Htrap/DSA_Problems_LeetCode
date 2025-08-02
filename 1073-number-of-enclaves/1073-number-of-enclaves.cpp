class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        grid[row][col] = 0;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //Traverse first and last row
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid);
            }
            if(grid[m - 1][i] == 1){
                dfs(m - 1, i, grid);
            }
        }

        // Traverse first and last col
        for(int j = 0; j < m; j++){
            if(grid[j][0] == 1){
                dfs(j, 0, grid);
            }
            if(grid[j][n - 1] == 1){
                dfs(j, n - 1, grid);
            }
        }

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};