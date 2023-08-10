// LC239 - Sliding Window Maximum

#include <vector>
#include <limits.h>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Deque Approach, using it to maintain a decreasing order queue
        vector<int> res;
        deque<int> d;

        // Setup initial window
        for (int i = 0; i < k; i++) {
            int elem = nums[i];
            while (!d.empty() && nums[d.back()] <= elem) { d.pop_back(); }
            d.push_back(i);
        }
        res.push_back(nums[d.front()]);

        // Begin sliding the window
        int l = 0;

        // Invariant: At the beginning of the loop body, 
            // 1) The max value in the window from l to l+k-1 is already calculated and stored
        for (int r = k; r < nums.size(); r++) {
            l++;
            if (l > d.front()) { d.pop_front(); } // Maintain a deque valid for our window indices

            while (!d.empty() && nums[d.back()] <= nums[r]) { d.pop_back(); } // Maintain decreasing order
            d.push_back(r);
            res.push_back(nums[d.front()]);
        }

        return res;
    }   
    // Following solution is correct, but too slow
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     // Idea #1: Use a set to store the k elements (no, if we update it we might remove a dupe?)
    //     // Idea #2: Use a priority queue?
    //         // Allows for duplicate values so we could easily pop and get max num
    //         // However, we would not be able to remove the first item in the window as we slide it
    //     // Idea #3: Use a umap (would need to find a way to quickly determine the max in there)

    //     /*
    //     If we used a umap, we could also keep a counter with the max for the current window. 
    //     If the item we remove (as we slide the window right) would cause the current max to no longer
    //     appear at all within the umap (map[max] == 0), then we know to update the max
    //     */
    //     vector<int> res;
    //     unordered_map<int, int> map;
    //     int maxN = INT_MIN; // Altenatively, we could use -10^4, given the constraint for nums[i]
    //     int n; // Convenience variable
    //     for (int i = 0; i < k; i++) {
    //         n = nums[i];
    //         map[n]++;
    //         if (n > maxN) {
    //             maxN = n;
    //         }
    //     }
    //     res.push_back(maxN);

    //     // Begin sliding the window
    //     int l = 0;

    //     // Invariant: At the beginning of the loop body, 
    //         // 1) The max value in the window from l to l+k-1 is already calculated and stored
    //     for (int r = k; r < nums.size(); r++) {
    //         map[nums[r]]++;
    //         map[nums[l]]--;
    //         l++;
    //         //cout << maxN << ":" << map[maxN] << "\n";
    //         if (map[maxN] == 0) {
    //             maxN = nums[l];
    //             for (int i = l+1; i < l+k; i++) {
    //                 maxN = max(maxN, nums[i]);
    //             }
    //         }
    //         maxN = max(maxN, nums[r]);
    //         res.push_back(maxN);
    //     }

    //     return res;
    // }   
};