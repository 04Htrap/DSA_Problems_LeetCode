class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(mid * mid == (long long) x) return mid;
            else if((mid * mid) <= (long long) x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};