class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int up = INT_MAX;
                int leftDiag = INT_MAX;
                int rightDiag = INT_MAX;

                if(i > 0) up = matrix[i][j] + dp[i - 1][j];
                //Right Diag
                if(j < n - 1) rightDiag = matrix[i][j] + dp[i - 1][j + 1];
                //Left Diag
                if(j > 0) leftDiag = matrix[i][j] + dp[i - 1][j - 1];
                dp[i][j] = min(up, min(leftDiag, rightDiag));
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
};