// LC74: Search a 2D Matrix

#include <vector>

class Solution {
public:
    // Apply binary search on a 2D vector, then 1D binary search to determine if target is in matrix
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size();
        int width = matrix[0].size();

        // Search to narrow down which row may contain the target
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target < matrix[mid][0]) {
                r = mid-1;
                if (mid == 0) { break; } // Check if there are still valid rows to check
            } else if (target > matrix[mid][width-1]) {
                l = mid+1;
                if (mid == matrix.size() - 1) { break; } // Check if there are still valid rows to check
            } else {
                return binarySearch(matrix[mid], target);
            }
        }

        return false;
    }

    // Function to search a 1D vector
    bool binarySearch(std::vector<int>& vec, int target) {
        int l = 0;
        int r = vec.size();
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (vec[mid] > target) {
                r = mid-1;
            } else if (vec[mid] < target) {
                l = mid+1;
            } else {
                return true;
            }
        }

        return false;
    }
};