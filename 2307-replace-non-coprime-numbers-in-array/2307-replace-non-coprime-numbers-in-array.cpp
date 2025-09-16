class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        st.push(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            long long x = nums[i];
            while(!st.empty()) {
                long long y = st.top();

                long long gcd = __gcd(x, y);
                if(gcd == 1) break;

                st.pop();
                x = (x * y) / gcd;
            }
            st.push(x);
        }

        vector<int> res;
        while (!st.empty()) {
            res.push_back((int)st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// class Solution {
// public:
//     vector<int> replaceNonCoprimes(vector<int>& nums) {
//         stack<long long> st;

//         for(int i = nums.size() - 1; i >= 0; i--) {
//             st.push(nums[i]);
//         }

//         vector<int> res;

//         while(st.size() > 1) {
//             long long x = st.top();
//             st.pop();
//             long long y = st.top();

//             long long gcd = __gcd(x, y);
//             long long lcm = (x * y) / gcd;

//             if(gcd != 1) {
//                 st.pop();
//                 st.push(lcm);
//             }
//             else {
//                 res.push_back(x);
//             }
//         }
//         res.push_back(st.top());
//         return res;
//     }
// };