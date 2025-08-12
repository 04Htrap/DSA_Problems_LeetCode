class Solution {
public:
    bool canFinish(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += ceil(double (piles[i]) / speed);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;

        sort(piles.begin(), piles.end());

        int high = piles[piles.size() - 1];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};