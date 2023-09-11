// LC875: Koko Eating Bananas

#include <vector>
#include <cmath>
#include <algorithm>
class Solution {
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        // Binary Search approach, O(n*logn) time, O(1) space
        // Apply binary search on the number k, since k can range from 1 up to piles.size()

        int l = 1, r = *std::max_element(piles.begin(), piles.end());
        int res = r; // Start with max possible value

        while (l <= r) {
            int mid = l + (r-l)/2;
            long hours = 0;
            for (auto i : piles) {
                hours += ceil(i/(double)mid);
            }

            // Determine whether to check left or right based on hours taken vs h
            if (hours <= h) {
                res = std::min(res, mid);
                r = mid-1;
            } else {
                l = mid+1;
            }   
        }
        return res;
    }
};