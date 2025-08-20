class Solution {
public:
    // int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> dp) {
    //     if (i < 0 || j < 0) return 0;
    //     if (matrix[i][j] == 0) return 0;
    //     if (dp[i][j] != -1) return dp[i][j];
        
    //     return dp[i][j] = 1 + min({solve(i-1, j, matrix, dp), solve(i, j-1, matrix, dp), solve(i-1, j-1, matrix, dp)});
    // }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) {
                    if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};