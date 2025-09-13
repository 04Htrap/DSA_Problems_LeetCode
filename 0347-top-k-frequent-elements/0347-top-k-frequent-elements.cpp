class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int num : nums) {
            freq[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minH;
        for(auto p : freq) {
            minH.push({p.second, p.first});
            if(minH.size() > k) minH.pop();
        }

        vector<int> ans;
        while(!minH.empty()) {
            ans.push_back(minH.top().second);
            minH.pop();
        }

        return ans;
    }
};