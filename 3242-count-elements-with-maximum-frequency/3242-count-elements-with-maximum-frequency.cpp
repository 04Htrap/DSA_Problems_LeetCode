class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        int ans = 0;
        for(int i = 0; i < freq.size(); i++) {
            if(freq[i] == maxFreq) ans += maxFreq;
        }
        return ans;
    }
};