class Solution {
public:
    int robHelper(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int prev1 = nums[start];
        int prev2 = 0;

        for(int i = start + 1; i < end; i++) {
            int take = nums[i] + prev2;
            int not_take = 0 + prev1;

            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int ans = max(robHelper(nums, 0, nums.size() - 1), robHelper(nums, 1, nums.size()));
        return ans;
    }
};