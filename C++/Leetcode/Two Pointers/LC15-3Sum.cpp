#include <vector>
#include <algorithm> // For sort
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        using namespace std;
        // Using hint 1, first idea is to iterate through nums, then using two ptrs to calculate a two sum to the complement of nums[i]
        // This would be O(n*n) = O(n^2) though? Does not look like it is possible to be more efficient in time complexity.
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end()); // This allows us to use a Two Sum II approach with Two Pointers in our inner loop

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i-1]) { continue; } // Skip past any duplicates for our "fixed number"

            int lp = i+1;
            int rp = n-1;
            int sum;

            while (lp < rp) {
                sum = nums[i] + nums[lp] + nums[rp];
                // Adjusting our two pointers if needed
                if (sum > 0) { rp--; }
                else if (sum < 0) { lp++; }
                else {
                    res.push_back({nums[i], nums[lp], nums[rp]});       // Append a new triplet to the result vector
                    lp++;
                    while (lp < rp && nums[lp] == nums[lp-1]) { lp++; }  // Skip past any duplicates (only need to change lp OR rp, not both)
                }
            }
        }

        return res;


    }
};