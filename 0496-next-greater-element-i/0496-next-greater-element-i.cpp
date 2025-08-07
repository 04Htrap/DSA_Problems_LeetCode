class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> s;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(s.empty()) next_greater[nums2[i]] = -1;
            else next_greater[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        vector<int> res;
        for(int num : nums1){
            res.push_back(next_greater[num]);
        }

        return res;
    }
};