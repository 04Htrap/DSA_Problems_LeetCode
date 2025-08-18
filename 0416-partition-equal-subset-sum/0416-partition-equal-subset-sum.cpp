class Solution {
public:
    bool isPossible(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if(target == 0) return true;

        if(idx == 0) return nums[0] == target;

        if(dp[idx][target] != -1) return dp[idx][target];

        bool not_taken = isPossible(idx - 1, target, nums, dp);

        bool taken = false;
        if(nums[idx] <= target) {
            taken = isPossible(idx - 1, target - nums[idx], nums, dp);
        }

        return dp[idx][target] = taken || not_taken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        if(totalSum % 2 == 1) return false;
            int target = totalSum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return isPossible(n - 1, target, nums, dp);

    }
};