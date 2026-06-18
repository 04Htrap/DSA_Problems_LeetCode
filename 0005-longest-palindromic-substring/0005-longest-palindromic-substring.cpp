class Solution {
public:
    //TC O(n^2)
    //SC O(1)
    string longestPalindrome(string s) {
        int startIdx = 0;
        int maxLen = 0;

        for(int i = 0; i < s.size(); i++) {
            //Check for odd length center
            int left = i;
            int right = i;

            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                //Increment and Decrement L and R
                //Before that update the maxLen and startIdx because that was the previous longest
                if((right - left + 1) > maxLen) {
                    maxLen = right - left + 1;
                    startIdx = left;
                }
                left--;
                right++;
            }

            //Check for even length center
            left = i;
            right = i + 1;

            while(left >= 0 && right < s.size() && s[left] == s[right]) {
                //Increment and Decrement L and R
                //Before that update the maxLen and startIdx because that was the previous longest
                if((right - left + 1) > maxLen) {
                    maxLen = right - left + 1;
                    startIdx = left;
                }
                left--;
                right++;
            }
        }

        return s.substr(startIdx, maxLen);
    }
};