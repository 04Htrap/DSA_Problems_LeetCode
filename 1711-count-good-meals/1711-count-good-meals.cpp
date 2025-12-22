class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long ans = 0;

        for (int x : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                int p = pow(2, i);
                int need = p - x;
                if (freq.count(need)) {
                    ans = (ans + freq[need]) % MOD;
                }
            }
            freq[x]++;
        }
        return ans;
    }
};