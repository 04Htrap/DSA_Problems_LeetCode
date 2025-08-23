class Solution {
public:
    int countPartitions(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int notTaken = countPartitions(idx - 1, target, nums, dp);

        int taken = 0;
        if (nums[idx] <= target)
            taken = countPartitions(idx - 1, target - nums[idx], nums, dp);
            
        return dp[idx][target] = (notTaken + taken);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum - target < 0) return 0;
        if ((totalSum - target) % 2 == 1) return 0;

        int n = nums.size();
        int s2 = (totalSum - target) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));

        return countPartitions(n - 1, s2, nums, dp);
    }
};