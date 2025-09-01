class Solution {
public:
    int maxDepth(string s) {
        int cntOpen = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cntOpen++;
                depth = max(depth, cntOpen);
            } 
            else if (s[i] == ')') {
                cntOpen--;
            }
        }
        return depth;
    }
};