class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char ch : s) {
            if (vowels.count(ch)) {
                return true; 
            }
        }
        return false;
    }
};