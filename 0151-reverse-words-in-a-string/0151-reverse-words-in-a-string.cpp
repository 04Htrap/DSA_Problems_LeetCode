class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;
        string res="";
        string temp = "";

        while (left <= right && s[left] == ' ') left++;
        while (right >= left && s[right] == ' ') right--;


        while(left <= right) {
            char c = s[left];
            if(c != ' ') {
                temp += c;
            }
            else if(temp != "") {
                if(res != "") res = temp + " " + res;
                else res = temp;
                temp = "";
            }
            left++;
        }

        if(temp != "") {
            if(res != "") res = temp + " " + res;
            else res = temp;
        }
        return res;
    }
};