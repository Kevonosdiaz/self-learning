// LC42: Trapping Rain Water

#include <vector>
#include <algorithm>
class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        int l[n];
        int r[n];

        int maxL = 0;
        int maxR = 0;
        int water = 0;

        int j;

        // Populate our arrays of max boundaries for every position in the input array
        for (int i = 0; i < n; i++) {
            j = n - 1 - i; // Track index in reverse
            if (height[i] > maxL) {
                maxL = height[i];
            }

            if (height[j] > maxR) {
                maxR = height[j];
            }

            l[i] = maxL;
            r[j] = maxR;
        }

        int minBound;
        for (int i = 0; i < n; i++) {
            minBound = std::min(l[i],r[i]);
            if (minBound > height[i]) {
                water += minBound - height[i];
            }
        }

        return water;
    }
};