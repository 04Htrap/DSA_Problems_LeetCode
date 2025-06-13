class Solution {
public:
    int minBitFlips(int start, int goal) {
        int helper = start ^ goal;
        int cnt = 0;
        while (helper > 0){
            cnt = cnt + (helper & 1); // Checks if helper number is odd and if yes it ans with 1 and gives 1 in return
            helper = helper >> 1; // To do n/2
        }

        if(helper == 1) cnt++;

        return cnt;
    }
};