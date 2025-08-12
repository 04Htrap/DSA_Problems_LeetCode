class Solution {
public:
    bool midPossible(vector<int>& weights, int mid, int days) {
        int calcDays = 1;
        int load = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(load + weights[i] > mid) {
                calcDays++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return calcDays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int weightsSum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < weights.size(); i++) {
            weightsSum += weights[i];
            maxi = max(weights[i], maxi);
        }

        int low = maxi; // Max Capacity;
        int high = weightsSum; // Max Sum of elements;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(midPossible(weights, mid, days)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};