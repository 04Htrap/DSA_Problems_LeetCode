class Solution {
public:
    int subCount(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<int, int> count;
        while(right < nums.size()) {
            count[nums[right]]++;
            while(count.size() > k) {
                count[nums[left]]--;
                if(count[nums[left]] == 0) 
                    count.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subCount(nums, k) - subCount(nums, k - 1);
    }
};