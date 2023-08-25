// LC704: Binary Search
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        return binSearch(nums, 0, nums.size()-1, target);
    }

    int binSearch(std::vector<int>& nums, int low, int high, int target) {
        if (low > high) { return -1; }

        int mid = low + (high - low)/2;
        if (nums[mid] == target) { 
            return mid;
        } else if (nums[mid] < target) {
            return binSearch(nums, mid+1, high, target);
        } 
        return binSearch(nums, low, mid-1, target);
    }
};