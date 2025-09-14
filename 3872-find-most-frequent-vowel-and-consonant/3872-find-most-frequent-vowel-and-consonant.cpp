class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;

        int conso = 0;
        int vow = 0;

        for(char c : s) freq[c]++;

        for(auto p : freq) {
            char ch = p.first;
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vow = max(vow, p.second);
            else
                conso = max(conso, p.second);
        }
        return vow + conso;
    }
};