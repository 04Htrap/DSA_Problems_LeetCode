class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        int ans=0;
        for(int i = 0; i < n.length(); i++){
            if(n[i]=='6'){
                n[i] = '9';
                break;
            }
        }
        for(int i = 0; i < n.length(); i++){
            ans = (ans*10)+(n[i]-'0');
        }
        return ans;
    }
};