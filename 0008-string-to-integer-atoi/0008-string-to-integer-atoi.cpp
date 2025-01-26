class Solution {
public:
    bool isDigit(char ch){
        int ans = false;
        if( ch >= '0' && ch <= '9')
            ans = true;
        return ans;
    }
    bool isSpace(char ch){
        int ans = false;
        if( ch == ' ' || ch == '\n')
            ans = true;
        return ans;
    }
    
    int myAtoi(string s){
        long result = 0;
        int i = 0;
        int sign = 1;
        
        while (i < s.length() && isSpace(s[i]))
            i++;
        
        if (i < s.length() && (s[i] == '+' || s[i] == '-')){
            if (s[i] == '-')
                sign = -1;
            else
                sign = 1;
            i++;
        }
        while (i < s.length() && isDigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
               return INT_MIN;
            }
            i++;
        }
        return result * sign;
        
    }
           
};