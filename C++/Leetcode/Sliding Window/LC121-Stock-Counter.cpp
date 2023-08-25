#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Using a sliding window approach in O(n)
        // As we iterate through array, keep checking if selling on day[i] would produce a greater profit
        // Also keep track of the cheapest price to buy, which is used with day[i] to calculate profit
    int maxProfit = 0;
    int minP = 10000; // Max possible value given problem constraints
    int profit;
    //int n = prices.size();
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minP) { minP = prices[i]; }

        //profit = prices[i] - minP;
        if (prices[i] - minP > maxProfit) { maxProfit = prices[i] - minP; }
    }
    
    return maxProfit;
    }

};