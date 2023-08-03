#include <vector>
#include <iostream>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        // Consider a similar approach to Trapping Rain Water?
        // O(n) Time & Memory
        // Pretty fast solution, but likely the Sliding Window solution will be O(1) Memory and still O(n) Time

        int n = prices.size();
        int r[n];
        int maxR = 0;

        for (int i = n-1; i >= 0; i--) {
            if (prices[i] > maxR) {
                maxR = prices[i];
            }
            r[i] = maxR;
        }

        int maxProfit = 0;
        int profit;

        for (int i = 0; i < n; i++) {
            profit = r[i] - prices[i];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};