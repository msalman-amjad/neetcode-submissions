class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Both pointers start at the beginning
        int left = 0; // Buy day
        int max_profit = 0;
        
        for (int right = 0; right < prices.size(); right++) {
            // Can we make a profit by selling today?
            if (prices[left] < prices[right]) {
                int current_profit = prices[right] - prices[left];
                max_profit = std::max(max_profit, current_profit);
            } 
            // If today's price is cheaper than our buy price,
            // make today our new buying day!
            else {
                left = right; 
            }
        }
        
        return max_profit;
    }
};