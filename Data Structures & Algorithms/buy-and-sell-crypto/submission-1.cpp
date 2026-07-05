class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Brute force approach
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int buy = prices[i];

            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - buy;
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};