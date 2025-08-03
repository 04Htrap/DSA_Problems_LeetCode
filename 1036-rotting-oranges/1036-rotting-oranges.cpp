class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited = grid;
        queue<pair<int, int>> q;
        int cntFresh = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 1){
                    cntFresh++;
                }
                if(visited[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(cntFresh == 0) return 0;
        if(q.empty()) return -1;

        int minutes = -1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int sz = q.size();
            minutes++;

            for(int i = 0; i < sz; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(int d = 0; d < 4; d++){
                    int nrow = row + delrow[d];
                    int ncol = col + delcol[d];

                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] == 1){
                        visited[nrow][ncol] = 2;
                        cntFresh--;
                        q.push({nrow, ncol});          
                    }
                }
            }
        }

        if(cntFresh == 0 )return minutes;
        else return -1;
    }
};