class Solution {
public:
    void DFS(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
       if (image[r][c] == oldColor) {
            image[r][c] = newColor;
            if (r >= 1) {
                DFS(image, r - 1, c, oldColor, newColor);
            }
            if (c >= 1) {
                DFS(image, r, c - 1, oldColor, newColor);
            }
            if (r + 1 < image.size()) {
                DFS(image, r + 1, c, oldColor, newColor);
            }
            if (c + 1 < image[0].size()) {
                DFS(image, r, c + 1, oldColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor != color) {
            DFS(image, sr, sc, oldColor, color);
        }
        return image;
    }
};