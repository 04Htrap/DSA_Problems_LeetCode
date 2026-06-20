class Solution {
public:
    //TIME COMPLEXITY O(nlogn)
    //SPACE COMPLEXITY O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];

        for(int i = 0; i < intervals.size(); i++) {
            if(curr[1] >= intervals[i][0]) {
                curr[1] = max(curr[1], intervals[i][1]);
            }
            else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};