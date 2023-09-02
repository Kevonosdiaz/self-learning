// LC4: Median Of Two Sorted Arrays

#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int total = m + n;

        // Perform our search on the smaller of the two vectors
        if (n < m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int l = 0, r = m;
        double res = 0.0;

        // We are guaranteed an answer given constraints, and a break is used when it is found
        while (l <= r) {
            int i = l + (r-l)/2;
            int j = (total + 1) /2 - i;

            // Account for edge cases (could also use -10^6 & 10^6 instead of MIN/MAX)
            int left1 = (i > 0) ? nums1[i-1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j-1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                // Return single digit when total is odd, and average of two middle digits for even total
                if (total % 2 == 0) {
                    res = (std::max(left1, left2) + std::min(right1, right2))/2.0;
                } else {
                    res = std::max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                // Reduce size of left A partition
                r = i - 1;
            } else {
                // Increase size of left A partition
                l = i + 1;
            }
        }

        return res;

    }
};