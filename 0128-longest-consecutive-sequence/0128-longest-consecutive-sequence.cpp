class Solution {
public:
    //TIME COMPLEXITY O(n)
    //SPACE COMPLEXITY O(1)
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int length = 0;

        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()) {
                int curr = num;
                int streak = 1;

                while(numSet.find(curr + 1) != numSet.end()) {
                    curr++;
                    streak++;
                }
                length = max(length, streak);
            }  
        }
        return length;
    }
};