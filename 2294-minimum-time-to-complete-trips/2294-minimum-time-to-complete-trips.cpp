class Solution {
public:
    bool isPossible(vector<int>& time, long long mid, int totalTrips) {
        long long trips = 0;
        for(int i = 0; i < time.size(); i++) {
            trips += mid / time[i];
        }

        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());

        long long low = 1;
        long long high = (long long)*min_element(time.begin(), time.end()) * totalTrips;
        long long ans = high;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            
            if(isPossible(time, mid, totalTrips)) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};