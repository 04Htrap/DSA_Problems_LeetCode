class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int partSum = totalSum / 3;

        if(totalSum % 3 != 0) return false;
        int sumCount = 0;
        int sum = 0;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if(sum == partSum) {
                sumCount++;
                sum = 0;
            }
        }
        if(sumCount > 2) return true;
        return false;
    }
};