// LC53: Maximum Subarray

#include <vector>
#include <algorithm>

class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            // Implement Kadane's algorithm:
            // Determine the max subarray value at every step (greedy)
            
            // Keep trackers for local and global maximum
            int local = nums[0], global = local;

            for (int i = 1; i < nums.size(); i++) {
                local = std::max(nums[i], local + nums[i]);
                if (local > global) global = local;
            }

            return global;
        }
};
