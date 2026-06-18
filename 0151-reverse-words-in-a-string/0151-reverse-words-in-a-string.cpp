class Solution {
public:
    //TC O(n)
    //SC O(1)
    string reverseWords(string s) {
        string res = "";

        int i = s.size() - 1;

        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') {
                i--;
            }
            if(i < 0)
                break;
            int end = i;

            while(i >= 0 && s[i] != ' ') {
                i--;
            }

            if(!res.empty()) {
                res += " ";
            }

            res.append(s, i + 1, end - i);
        }
        return res;

        //TIME COMPLEXITY O(N) but SPACE COMPLEXITY O(n)
        // vector<string> words;
        // string word = "";

        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] != ' ') {
        //         word += s[i];
        //     }
        //     else if(!word.empty()) {
        //         words.push_back(word);
        //         word = "";
        //     }
        // }

        // if(!word.empty()) {
        //     words.push_back(word);
        // }

        // reverse(words.begin(), words.end());
        // string res = "";
        // for(int i = 0; i < words.size(); i++) {
        //     res += words[i];
        //     if(i < words.size() - 1) {
        //         res += " ";
        //     }
        // }
        // return res;
    }
};