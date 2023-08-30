// LC33: Search in Rotated Sorted Array

#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            int val = nums[mid];

            // Check if mid is the target
            if (val == target) {
                return mid;
            }

            // Distinguish which side of mid contains the pivot
            bool leftPivot =  nums[r] > val;

            if (leftPivot) {
                // First check whether it belongs between mid and end
                if (target > val && target <= nums[r]) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            } else { 
                if (target < val && target >= nums[l]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }

        return -1;
    }
};