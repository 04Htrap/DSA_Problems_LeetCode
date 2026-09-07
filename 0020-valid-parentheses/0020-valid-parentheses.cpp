class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;
                
                char top = st.top();
                st.pop();

                if((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '['))
                    return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};