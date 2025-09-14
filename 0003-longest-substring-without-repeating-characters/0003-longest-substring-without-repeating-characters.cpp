class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int maxLen = 0;
        unordered_set<int> dupli_checker;

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            if(dupli_checker.find(s[right]) != dupli_checker.end()) {
                while(left < right && dupli_checker.find(s[right]) != dupli_checker.end()) {
                    dupli_checker.erase(s[left]);
                    left++;
                }
            }
            dupli_checker.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};