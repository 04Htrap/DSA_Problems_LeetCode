class Solution {
public:
    //TIME COMPLEXITY O(n)
    //SPACE COMPLEXITY O(n)
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }
        unordered_set<int> st;
        int maxLen = 0;
        int left = 0;
        for(int right = 0; right < s.length(); right++) {
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};