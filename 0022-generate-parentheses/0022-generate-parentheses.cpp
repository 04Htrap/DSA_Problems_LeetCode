class Solution {
public:
    
    void generate(vector<string> &result, string current, int open, int close, int pairs){
        if(current.size() == 2 * pairs) {
            result.push_back(current);
            return;
        }

        if(open < pairs) generate(result, current + "(", open + 1, close, pairs);
        if(close < open) generate(result, current + ")", open, close + 1, pairs);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, 0, n);
        return result;
    }
};