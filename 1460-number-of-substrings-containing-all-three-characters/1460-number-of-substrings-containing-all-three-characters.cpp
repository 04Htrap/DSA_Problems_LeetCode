class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};

        while(right < s.length()) {
            char_count[s[right]]++;

            while(char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
                count += s.length() - right;
                char_count[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};