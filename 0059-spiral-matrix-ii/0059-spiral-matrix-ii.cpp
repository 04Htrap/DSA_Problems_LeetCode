class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        int currVal = 1;
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        while(top <= bottom && left <= right) {
            //top row traverse
            for(int i = left; i <= right; i++) {
                matrix[top][i] = currVal;
                currVal++;
            }
            top++;

            //Right col traverse
            for(int i = top; i <= bottom; i++){
                matrix[i][right] = currVal;
                currVal++;
            }
            right--;

            //Bottom row traverse
            if(top <= bottom) {
                for(int i = right; i >= left; i--){
                    matrix[bottom][i] = currVal;
                    currVal++;
                }
                bottom--;
            }

            // Left col traverse
            if(left <= right) {
                for(int i = bottom; i >= top; i--){
                    matrix[i][left] = currVal;
                    currVal++;
                }
                left++;
            }
        }
        return matrix;
    }
};