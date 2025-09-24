class Solution {
public:
    int trailingZeroes(int n) {
        int cnt_multiple = 0;

        while(n > 0) {
            n = n / 5;
            cnt_multiple += n;
        }
        return cnt_multiple;
    }
};