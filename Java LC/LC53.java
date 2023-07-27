class Solution {
    // Given an integer array nums, find the subarray with the largest sum, and return its sum.
    public int maxSubArray(int[] nums) {
        // Implementing Kadane's algorithm:
        int globalMax = nums[0];
        int currentMax = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currentMax = Math.max(currentMax + nums[i], nums[i]); // either the single element or the single element + the previous max
            if (currentMax > globalMax) {
                globalMax = currentMax;
            }
        }
        return globalMax;
    }
}
