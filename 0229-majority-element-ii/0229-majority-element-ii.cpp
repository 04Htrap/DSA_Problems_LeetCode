class Solution {
public:
    //TIME COMPLEXITY O(n)
    //SPACE COMPLEXITY O(1)
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = 0;
        int cnt1 = 0;

        int el2 = 0;
        int cnt2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == el1)
                cnt1++;
            else if(nums[i] == el2)
                cnt2++;
            else if(cnt1 == 0) {
                el1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                el2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }

        vector<int> res;
        if(cnt1 > (nums.size() / 3)) res.push_back(el1);
        if(cnt2 > (nums.size() / 3) && el2 != el1) res.push_back(el2);

        return res;
    }
};