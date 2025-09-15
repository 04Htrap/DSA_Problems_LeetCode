class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        vector<string> words;
        string word = "";

        for (char c : text) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);

        int ans = 0;
        for (string w : words) {
            bool canType = true;
            for (char ch : w) {
                if (broken.count(ch)) {
                    canType = false;
                    break;
                }
            }
            if (canType == true) ans++;
        }

        return ans;
    }
};