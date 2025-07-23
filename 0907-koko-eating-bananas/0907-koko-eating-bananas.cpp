class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    long long calculateHours(vector<int>& piles, int speed) {
        long long totalH = 0;
        for(int i = 0; i < piles.size(); i++){
            totalH += ceil((double)piles[i] / speed);
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while(low <= high){
            int mid = (high + low) / 2;
            long long totalH = calculateHours(piles, mid);

            if(totalH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};