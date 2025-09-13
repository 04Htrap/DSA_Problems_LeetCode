class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int num : nums) {
            mp[num]++;
        }

        vector<int> res;
        for(auto cnt : mp) {
            if(cnt.second == 2) res.push_back(cnt.first);
        }
        return res;
    }
};