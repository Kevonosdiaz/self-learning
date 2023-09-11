// LC153: Find Minimum in Rotated Sorted Array

#include <vector>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        
        // Perform binary search to find largest number, which should be before the min
        while (l < r) {
            int mid = l + (r-l)/2;

            // Narrow the search
            if (nums[mid] < nums[nums.size()-1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }

        return nums[l];
    }
};