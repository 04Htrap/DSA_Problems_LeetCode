class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0;
        double area;

        for(int i = 0; i < n; i++) { //all 1s
            for(int j = i + 1; j < n; j++) { //all 2s
                for(int k = j + 1; k < n; k++) { //all 3s
                    // Use area formula Area = 1/2 * mod(x1(y2 - y3) + x2(y1 - y3) + x3(y2 - y1))
                    area = 0.5 * abs(
                        points[i][0] * (points[j][1] - points[k][1]) +
                        points[j][0] * (points[k][1] - points[i][1]) +
                        points[k][0] * (points[i][1] - points[j][1])
                    );

                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};