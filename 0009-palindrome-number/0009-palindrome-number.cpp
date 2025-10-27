class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0; // To check reverse for palindrome
        int num = x; // To store orignal number

        while (num > 0) {
            if (rev > INT_MAX / 10) return false; 
            rev = rev * 10 + num % 10;
            num /= 10;
        }

        if(rev == x) return true;
        return false;
    }
};