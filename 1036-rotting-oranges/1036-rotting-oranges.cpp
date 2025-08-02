class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited = grid;

        queue<pair<int, int>> q;
        int cntFresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 2) {
                    q.push({i, j});
                }
                if (visited[i][j] == 1) {
                    cntFresh++;
                }
            }
        }

        if (cntFresh == 0)
            return 0;
        if (q.empty())
            return -1;

        int minutes = -1;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                pair<int, int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;

                for (int k = 0; k < 4; ++k) {
                    int dx = dirs[k].first;
                    int dy = dirs[k].second;
                    int i = x + dx;
                    int j = y + dy;

                    if (i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1) {
                        visited[i][j] = 2;
                        cntFresh--;
                        q.push({i, j});
                    }
                }
            }
            minutes++;
        }

        if(cntFresh == 0) return minutes;
        else return -1;
    }
};