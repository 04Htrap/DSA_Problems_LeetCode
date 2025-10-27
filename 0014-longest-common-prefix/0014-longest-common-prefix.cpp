class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        string pref = strs[0];
        for(int i = 0; i < strs.size(); i++) {
            while(strs[i].find(pref) != 0) pref.pop_back();
        }
        return pref;
    }
};