class Solution {
public:
    //TIME COMPLEXITY O(n * m)
    //SPACE COMPLEXITY O(n + m)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        //Mark rows and cols which have 0 values
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        //Mark the cells zero
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(row[i] == 1 || col[j] == 1) 
                    matrix[i][j] = 0;
            }
        }
    }
};