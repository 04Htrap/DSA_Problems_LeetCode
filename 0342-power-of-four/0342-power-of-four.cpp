class Solution {
public:
    bool isPowerOfFour(int n) {

        if(n<=0) return false;
        
        long long t = (long long)log2(n)/2;

        return pow(4,t)==n;



    }
};