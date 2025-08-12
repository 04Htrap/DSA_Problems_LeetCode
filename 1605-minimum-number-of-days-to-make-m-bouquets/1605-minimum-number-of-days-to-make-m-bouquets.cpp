class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int mid, int m, int k) {
        int adjCnt = 0;
        int bCnt = 0;

        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                adjCnt++;
            }
            else {
                bCnt = bCnt + (adjCnt / k);
                adjCnt = 0;
            }
        }
        bCnt = bCnt + (adjCnt / k);
        return bCnt >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m * k) return -1;

        int low = INT_MAX;
        int high = INT_MIN;
        for(int i = 0; i < bloomDay.size(); i++){
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(bloomDay, mid, m, k)) high = mid - 1;
            else low = mid + 1;
        } 
        return low;
    }
};