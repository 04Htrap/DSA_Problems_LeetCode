class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int posInd = 0;
        int negInd = 1;
        vector<int> result(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                result[posInd] = nums[i];
                posInd += 2;
            }
            else{
                result[negInd] = nums[i];
                negInd += 2;
            }
        }
        return result;
    }
};