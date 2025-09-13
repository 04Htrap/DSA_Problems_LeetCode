class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        vector<int> res(n);
        int insertPos = n - 1;
        while(left <= right) {
            if(abs(nums[right]) > abs(nums[left])) {
                res[insertPos] = nums[right] * nums[right];
                right--;
                insertPos--;
            }
            else {
                res[insertPos] = nums[left] * nums[left];
                left++;
                insertPos--;
            }
        }
        return res;
    }
};