class Solution {
public:
    
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, firstPos = -1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
        
            if (nums[mid] == target) {
                firstPos = mid;
                high = mid - 1;
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
    
    return firstPos;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, lastPos = -1;
    
        while (low <= high) {
            int mid = low + (high - low) / 2;
        
            if (nums[mid] == target) {
                lastPos = mid;
                low = mid + 1;
            } 
            else if (nums[mid] < target) {
                low = mid + 1;
            } 
            else {
                high = mid - 1;
            }
        }
    
    return lastPos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
    
        return {first, last};
    }
};