class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minX = INT_MAX;
        int maxX = INT_MIN;

        int minY = INT_MAX;
        int maxY = INT_MIN;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    minX = min(minX, i);
                    maxX = max(maxX, i);
                    minY = min(minY, j);
                    maxY = max(maxY, j);

                }
            }
        }

        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};