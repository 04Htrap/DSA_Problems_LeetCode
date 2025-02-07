class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int min_price = INT_MAX;
        int profit;
        for(int i = 0; i < prices.size(); i++){
            min_price = min(min_price, prices[i]);
            profit = prices[i] - min_price;
            max_prof = max(max_prof, profit);
        }
        return max_prof;
    }
};