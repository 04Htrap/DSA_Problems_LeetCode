class Solution {
public:
    int partCount(vector<int>& nums, int mid) {
        int partNo = 1;
        int subSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(subSum + nums[i] <= mid) {
                subSum += nums[i];
            }
            else{
                partNo++;
                subSum = nums[i];  
            }    
        }
        return partNo;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());
        
        int low = maxi;
        int high = sum;
        int ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(partCount(nums, mid) <= k){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }   
};