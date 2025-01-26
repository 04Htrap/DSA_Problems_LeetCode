class Solution {
public:
    const int mini = INT_MIN;
    const int maxi = INT_MAX;
    
    double myPow(double x, int n) {

        // double a = 1.0;
        // if(x==1.0) return x;

        // if(n<0 && n==mini){
        //     n = n+1;
        //     n = abs(n);

        //     x = 1/x;
        //     for(int i=0; i<abs(n); i++){
        //         a *= x;
        //     }
            
        //     a *= x;
        //     return a;
        // }

        // else if(n<0){
        //     x = 1/x;
        // }

        // for(int i=0; i<abs(n); i++){
        //     a *= x;
        // }

        // return a;

        double a = pow(x, n);
        return a;
    }
};