class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int giveCandies = 1;

        for(int i = 0; candies > 0; i++) {
            res[i % num_people] += min(giveCandies, candies);
            candies -= giveCandies;
            giveCandies++;            
        }
        return res;
    }
};