class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int maxlen = 0;
        unordered_set<int> check_dupli;

        int left = 0;
        for(int right = 0; right < s.length(); right++){
            if(check_dupli.find(s[right]) != check_dupli.end()){
                while (left < right && check_dupli.find(s[right]) != check_dupli.end()){
                    check_dupli.erase(s[left]);
                    left++;
                }  
            }
            check_dupli.insert(s[right]);
            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};