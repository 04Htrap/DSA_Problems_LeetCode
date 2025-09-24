class Solution {
public:
    static bool comp(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return s1 + s2 > s2 + s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);

        string res;
        for(int num : nums) {
            res += to_string(num);
        }
        if(nums[0] == 0) return "0";
        return res;
    }
};