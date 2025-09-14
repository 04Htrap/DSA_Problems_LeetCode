class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLen = 0;

        for(char c = 'A'; c <= 'Z'; c++) {
            int left = 0;
            int replacement = 0;
            int right = 0;

            while(right < s.length()) {
                if(s[right] != c) {
                    replacement++;
                }

                while(replacement > k) {
                    if(s[left] != c) replacement--;
                    left++;
                }

                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }

        return maxLen;
    }
};