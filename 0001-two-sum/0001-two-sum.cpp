class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > numsIndex;
        for(int i = 0; i < nums.size(); i++){
            numsIndex.push_back({nums[i], i});
        }

        sort(numsIndex.begin(), numsIndex.end());
        int left = 0, right = numsIndex.size()-1;
        while (left < right) {
            int sum = numsIndex[left].first + numsIndex[right].first;
            if (sum == target) {
                return {numsIndex[left].second, numsIndex[right].second};
            }
            else if (sum < target) left++;
            else right--;
        }
        return {};
    }
};