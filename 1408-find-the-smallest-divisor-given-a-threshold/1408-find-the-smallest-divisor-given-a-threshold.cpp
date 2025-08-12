class Solution {
public:
    bool sumPossible(vector<int>& nums, int mid, int threshold) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)mid);
        }

        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        if(nums.size() > threshold) return -1;

        int low = 1;
        int high = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            high = max(high, nums[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(sumPossible(nums, mid, threshold)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};