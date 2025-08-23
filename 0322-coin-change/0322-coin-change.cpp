class Solution {
public:
    int findLowest(int idx, vector<int>& coins, int target, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target % coins[0] == 0) return target / coins[0];
            return INT_MAX; 
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int not_take = 0 + findLowest(idx - 1, coins, target, dp);
        int take = INT_MAX;
        if (coins[idx] <= target) {
            int res = findLowest(idx, coins, target - coins[idx], dp);
            if (res != INT_MAX) take = 1 + res;
        }

        return dp[idx][target] = min(take, not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = findLowest(n - 1, coins, amount, dp);
        if(ans >= INT_MAX) return -1;
        else return ans;
    }
};