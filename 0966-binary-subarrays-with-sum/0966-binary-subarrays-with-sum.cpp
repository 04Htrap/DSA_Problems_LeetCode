class Solution {
public:
    int countSub(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int left = 0, right = 0, sum = 0, sub_count = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum > goal) {
                sum -= nums[left];
                left++;
            }

            sub_count += (right - left + 1);
            right++;
        }

        return sub_count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSub(nums, goal) - countSub(nums, goal - 1);
    }
};