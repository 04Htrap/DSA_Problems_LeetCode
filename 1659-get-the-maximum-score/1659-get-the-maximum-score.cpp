class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int MOD = 1e9 + 7;
        int n = nums1.size();
        int m = nums2.size();

        int i = 0;
        int j = 0;

        long long sum1 = 0;
        long long sum2 = 0;

        long long result = 0;

        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                sum2 += nums2[j];
                j++;
            }
            else {
                result += max(sum1, sum2) + nums1[i];
                result = result % MOD;
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }
        
        while(i < nums1.size()) {
            sum1 += nums1[i];
            i++;
        }

        while(j < nums2.size()) {
            sum2 += nums2[j];
            j++;
        }

        result += max(sum1, sum2);
        return result % MOD;
    }
};