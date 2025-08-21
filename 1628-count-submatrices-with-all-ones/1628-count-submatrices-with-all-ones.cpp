class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> heights(n, 0);
        int total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }

            for (int j = 0; j < n; j++) {
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    if (heights[k] == 0) break;
                    minHeight = min(minHeight, heights[k]);
                    total += minHeight;
                }
            }
        }
        return total;
    }
};