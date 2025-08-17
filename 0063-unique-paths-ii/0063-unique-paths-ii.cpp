class Solution {
public:
    int countWays(int m, int n, vector<vector<int>>& dp, vector<vector<int>>& grid) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) { 
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;

                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        return countWays(m, n, dp, grid);
    }
};